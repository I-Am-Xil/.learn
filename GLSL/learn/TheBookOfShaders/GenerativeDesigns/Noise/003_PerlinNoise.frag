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

float PerlinNoise(float x){
    float i = floor(x);
    float f = fract(x);
    float noise = mix(Rand(i), Rand(i+1), smoothstep(0., 1., f));
    return noise;
}

float Noise(float t){
    return mix(PerlinNoise(t), abs(sin(t)), PerlinNoise(t) * (0.5+sin(t)/2));
}

float Band(float scale, vec2 blur, float axis){
    axis += 0.5;
    scale += 0.5;
    float s1 = smoothstep(scale + blur.x, scale - blur.x, axis);
    float s2 = smoothstep(scale + blur.y, scale - blur.y, 1.-axis);
    return s1*s2;
}

float GraphFunction(vec2 uv, float function){
    uv.y -= function;
    float graph = Band(0.05, vec2(0.01), uv.y);
    return graph;
}

mat2 Rotate2D(float angle){
    return mat2(cos(angle), -sin(angle),
                sin(angle), cos(angle));
}

float Circle(vec2 uv, float size, float blur){
    return smoothstep(0.0, blur, length(uv) - size);
}

float Rand2D(vec2 uv){
    return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

float RandPixel(vec2 uv, float scale){
    uv *= scale;
    vec2 ipos = floor(uv);
    return Rand2D(ipos);
}


void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    float shape = 0.0;

    float r = length(uv);
    float a = atan(uv.y, uv.x);
    float f = 0.;
    shape = smoothstep(r, r+0.01, f);

    //NOTE: No borrar estas 2 lineas
    //r = length(uv)*cos(PerlinNoise(uv.x * u_time));
    //shape = smoothstep(r, r+0.01, 0.5);

    //shape = smoothstep(0.0, 0.01, length(uv) - 0.5 - PerlinNoise(dot(uv.x, uv.y)*(sin(u_time)+1)));
    //shape = smoothstep(0.0, 0.01, length(uv) - 0.5 - PerlinNoise(length(RandPixel(uv, 10.0))*(sin(u_time)+1)));

    //uv.y = uv.y*sin(uv.x*u_time);
    //shape = smoothstep(0.0, 0.01, length(uv) - 0.5);
    //uv.y = uv.y*sin(uv.y*u_time);

    //shape = PerlinNoise(u_time);
    //uv *= 10;
    //shape = GraphFunction(uv, mix(PerlinNoise(uv.x), abs(sin(uv.x)), PerlinNoise(uv.x) * (0.5+sin(uv.x)/2)));

    f = 0.5 + 0.5*Noise(5*sin(a)+0.1*(sin(u_time)));
    shape = smoothstep(r, r+0.01, f);

    vec3 color = vec3(shape);

    //r = length(uv+vec2(0, (sin(u_time)-2.)/2.));
    r = length(uv+vec2(0, sin(u_time)-2.0)/2.);
    f = 0.2;
    //color.r = max(smoothstep(r, r+0.01, f), shape);
    color.r = max(smoothstep(r, r+0.01, f), shape);

    fragColor = vec4(color, 1.0);
}
