#version 460
#ifdef GL
precision mediump float;
#endif

out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

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

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    vec3 color = vec3(1.0);
    float mouse_x = u_mouse.x/u_resolution.x; 

    uv.x += step(1., mod(uv.y, 2.)) * sin(u_time);

    uv.y = fract(35.*uv.y);

    for(int i = 0; i < 30; i++){
        color -= Rectangle(uv+(vec2(0.015, 0.)+vec2(0.01, 0.))*i, vec2(0.007, 0.65), vec4(0.001)) * mouse_x;
    }




    fragColor = vec4(color, 1.0);
}
