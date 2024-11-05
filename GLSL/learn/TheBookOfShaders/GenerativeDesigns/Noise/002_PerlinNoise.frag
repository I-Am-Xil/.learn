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

float Circle(vec2 uv, float scale, float blur){
    return smoothstep(scale + blur, scale - blur, length(uv));
}

mat2 Rotate2D(float angle){
    return mat2(cos(angle), -sin(angle),
                sin(angle), cos(angle));
}

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    float shape = 0.0;

    float r = length(uv);
    float a = atan(uv.y, uv.x);

    float f = a;

    int nCircles = 24;

    for(int i = 0; i < nCircles; i++){
        shape += Circle(uv*Rotate2D(-u_time/2.+2*PI*i/nCircles)+0.7*PerlinNoise(u_time), 0.03, 0.01);
    }




    vec3 color = vec3(shape);

    fragColor = vec4(color, 1.0);
}
