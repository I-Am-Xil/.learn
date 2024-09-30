#version 460
#ifdef GL
precision mediump float;
#endif

out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

float Rand(float seed){
    return fract(sin(seed)*100000.);
}

float Rand2(float seed){
    float p = fract(sin(seed)*100000.);
    return p*p;
}

float Rand3(float seed){
    return sqrt(fract(sin(seed)*100000.));
}

float Rand4(float seed){
    float p = fract(sin(seed)*100000.);
    return p*p*p*p*p;
}

float Rand2D(vec2 uv){
    return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    vec3 color = vec3(0.0);

    uv *= 10.;
    vec2 ipos = floor(uv);
    vec2 fpos = fract(uv);

    color = vec3(Rand2D(ipos));
    //color = vec3(Rand2D(fpos));
    //color = vec3(Rand2D(ipos+u_time)*Rand2D(fpos+u_time));




    fragColor = vec4(color, 1.0);
}
