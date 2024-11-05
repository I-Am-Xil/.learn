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

    //TECH: Cubic Hermine Curve. Same as smoothstep(...) for (0, 1)
    vec2 u = fpos*fpos*(3.0-2.0*fpos);
    //u = smoothstep(0., 1., fpos);

    //TECH: Mix 4 corners percentages
    return mix(a, b, u.x) + (c-a)*u.y*(1.-u.x) + (d-b)*u.x*u.y;
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


    vec2 pos = uv*10*(1.0+sin(u_time)/10.)*Rotate2D(u_time);
    shape = Noise2D(pos);
    vec3 color = vec3(shape);

    fragColor = vec4(color, 1.0);
}
