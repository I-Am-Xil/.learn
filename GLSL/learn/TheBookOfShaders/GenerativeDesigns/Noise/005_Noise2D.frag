#version 460

#ifdef GL
precision mediump float;
#endif

layout(location = 0) out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

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

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    vec2 uvMouse = u_mouse/u_resolution;
    float shape = 0.0;

    float r = length(uv);
    float a = atan(uv.y, uv.x);
    float f = a;

    shape = Noise2D(10*uv+100*Rand2D(uvMouse)*Rand2D(uvMouse));
    vec3 color = vec3(shape);

    fragColor = vec4(color, 1.0);
}
