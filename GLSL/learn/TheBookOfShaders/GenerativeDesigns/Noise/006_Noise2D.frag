#version 460

#ifdef GL
precision mediump float;
#endif

layout(location = 0) out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

float Rand(float seed){
    return fract(sin(seed)*100000.);
}

float Rand2D(vec2 uv){
    return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

float Noise2D(vec2 uv){
    vec2 ipos = floor(uv);
    vec2 fpos = fract(uv);

    float a = Rand2D(ipos);
    float b = Rand2D(ipos + vec2(1., 0.));
    float c = Rand2D(ipos + vec2(0., 1.));
    float d = Rand2D(ipos + vec2(1., 1.));

    vec2 u = smoothstep(0., 1., fpos);

    return mix(a, b, u.x) + (c-a)*u.y*(1.-u.x) + (d-b)*u.x*u.y;
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

vec3 hsb2rgb(vec3 c){
    vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),6.0)-3.0)-1.0, 0.0, 1.0);
    rgb = rgb*rgb*(3.0-2.0*rgb);
    return c.z * mix(vec3(1.0), rgb, c.y);
}

vec3 Background(vec2 uv){
    uv /= 1.2;

    float background;
    vec3 color = vec3(0);

    float backgroundLayer1 = Noise2D(uv*100 + Noise2D(uv*50 + u_time) + u_time/10);
    vec3 redColor = hsb2rgb(vec3(0.0, 1.0, 0.5));
    color = mix(color, redColor, smoothstep(0., 1., 0.3+backgroundLayer1));

    float backgroundLayer2 = 0.5*Noise2D(uv*10.0);
    backgroundLayer2 = mix(backgroundLayer2, backgroundLayer1, smoothstep(0.0, 0.5, 1-Noise2D(uv*10 + Noise2D(uv*10 + u_time/2) + u_time/10)));
    vec3 orangeColor = hsb2rgb(vec3(0.115, 1.0, 1.0));
    color = mix(color, orangeColor, 0.5*backgroundLayer2);

    return color;
}

vec3 Foreground(vec2 uv){
    vec3 color = vec3(0.0);

    float rect1 = Rectangle(uv, vec2(0.33, 0.8) + 0.05*Noise2D(uv*100 + u_time), vec4(0.001));
    float rect2 = Rectangle(uv + vec2(0.75, 0.0), vec2(0.30, 0.78) + 0.05*Noise2D(uv*100 + u_time), vec4(0.001));
    float rect3 = Rectangle(uv + vec2(-0.75, 0.0), vec2(0.30, 0.72) + 0.05*Noise2D(uv*100 + u_time), vec4(0.001));




    color = vec3(rect1 + rect2 + rect3);

    return color;
}


void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;

    float r = length(uv);
    float a = atan(uv.y, uv.x);
    float f = a;

    vec3 color = vec3(0.0);

    color = Background(uv);
    color = max(color, Foreground(uv));



    fragColor = vec4(color, 1.0);
}
