#version 460

#ifdef GL
precision mediump float;
#endif

layout(location = 0) out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

const float PI = 3.14159265359;

float Rand(float seed){
    return fract(sin(seed)*100000.);
}

float PerlinNoise1D(float x){
    float i = floor(x);
    float f = fract(x);
    float noise = mix(Rand(i), Rand(i+1), smoothstep(0., 1., f));
    return noise;
}

float PerlinNoise1DSharp(float x){
    float i = floor(x);
    float f = fract(x);
    float noise = mix(Rand(i), Rand(i+1), f);
    return noise;
}

float Rand2D(vec2 uv){
    return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

float RandPixel(vec2 uv, float scale){
    uv *= scale;
    vec2 ipos = floor(uv);
    return Rand2D(ipos);
}

float Band(float scale, vec2 blur, float axis){
    axis += 0.5;
    scale += 0.5;
    float s1 = smoothstep(scale + blur.x, scale - blur.x, axis);
    float s2 = smoothstep(scale + blur.y, scale - blur.y, 1.-axis);
    return s1*s2;
}

float Rectangle(vec2 uv, vec2 scale, vec4 blur){
    float xBand = Band(scale.x, blur.xz, uv.x);
    float yBand = Band(scale.y, blur.yw, uv.y);
    return xBand * yBand;
}

float Noise1D(float v){
    return cos(v + cos(v * 90.1415) * 100.1415) * 0.5 + 0.5;
}

float RowColumn(float axis){
    return round(0.5+sin( (10*axis+1)*PI )/2.);
}

vec3 hsb2rgb(vec3 c){
    vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),6.0)-3.0)-1.0, 0.0, 1.0);
    rgb = rgb*rgb*(3.0-2.0*rgb);
    return c.z * mix(vec3(1.0), rgb, c.y);
}

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    float shape = 0.0;

    shape = Rectangle(fract(uv*10)-0.5, vec2(0.3), vec4(0.15));
    //shape *= round((0.5+sin(u_time*10.)/2.));
    //shape *= max(RowColumn(uv.x), RowColumn(uv.y));

    uv *= 10;

    //shape *= round(PerlinNoise1D(10*u_time*RandPixel(uv, 1.0)));
    //shape *= PerlinNoise1D(10*u_time*RandPixel(uv, 1.0));
    shape = PerlinNoise1D(0.5*u_time*RandPixel(uv, 1.0));

    vec3 color = vec3(shape);

    color *= hsb2rgb(vec3(0.6, 1.0, 1.0));
    color = mix(color, hsb2rgb(vec3(0.6, 0.9, 1.0)), 1-smoothstep(0.0, 0.50, shape));

    fragColor = vec4(color, 1.0);
}
