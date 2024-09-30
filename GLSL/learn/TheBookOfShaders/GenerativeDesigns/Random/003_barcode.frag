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

vec2 TilesBrick(vec2 uv){
    uv.x += step(1., mod(uv.y, 2.)) * 0.5;
    return fract(uv);
}

float Rand2D(vec2 uv){
    return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

float Rand(float seed){
    return fract(sin(seed)*100000.);
}

float Stage1(vec2 uv, float speed){
    uv.x += step(1., mod(uv.y, 2.)) * speed;
    uv.x -= step(1., mod(-uv.y, 2.)) * speed;
    uv.x = fract(uv.x);

    return step(0.5, Rand(round(50.*uv.x)));
}

float Stage2(vec2 uv, float size, float speed){
    uv.x *= step(1., mod(uv.y, 2.));
    uv.x += step(1., mod(uv.y, 2.)) * speed;
    uv.x = fract(size*uv.x);
    return 1. - step(0.5, round(uv.x));
}

float Stage3(vec2 uv, float size, float speed){
    uv.x *= step(1., mod(-uv.y, 2.));
    uv.x -= step(1., mod(-uv.y, 2.)) * speed ;
    uv.x = fract(size*uv.x);
    return 1. - step(0.5, round(uv.x));
}

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    vec3 color = vec3(1.0);

    if(mod(u_time, 10.) > 9.){
        color = vec3(Stage1(uv, u_time*4.));
    }else if(mod(u_time, 10.) > 8.){
        color = vec3(Stage2(uv, 10., u_time*8.));
    }else if(mod(u_time, 10.) > 7.){
        color = vec3(Stage3(uv, 10., u_time*8.));
    }else if(mod(u_time, 10.) > 6.){
        color = vec3(Stage2(uv, 10., u_time*8.));
    }else if(mod(u_time, 10.) > 5.){
        color = vec3(Stage1(uv, -u_time*1.5));
    }else if(mod(u_time, 10.) > 4.){
        color = vec3(1.);
    }else if(mod(u_time, 10.) > 3.){
        color = vec3(Stage3(uv, 10., u_time*2.));
    }else if(mod(u_time, 10.) > 2.){
        color = vec3(Stage1(uv, round(u_time+1.) * 0.2));
    }else if(mod(u_time, 10.) > 1.){
        color = vec3(Stage3(uv, 8., u_time*4.));
    }else if(mod(u_time, 10.) > 0.){
        color = vec3(Stage2(uv, 8., u_time*4.));
    }

    fragColor = vec4(color, 1.0);
}
