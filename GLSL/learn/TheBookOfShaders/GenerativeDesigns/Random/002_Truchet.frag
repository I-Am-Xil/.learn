#version 460
#ifdef GL
precision mediump float;
#endif

out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

const float PI = 3.14159265359;

float Random2D(vec2 coord){
    return fract(sin(dot(coord.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

vec2 Tile(vec2 uv, float subdiv){
    uv *= subdiv;
    return fract(uv);
}

mat2 Rotate2D(float angle){
    return mat2(cos(angle), -sin(angle),
                sin(angle), cos(angle));
}

vec2 TileRotatePattern(vec2 uv){
    float rot = step(1., mod(uv.y, 2.));
    rot += step(1., mod(uv.x, 2.));
    rot += 2. * step(1., mod(-uv.y, 2.)) * step(1., mod(uv.x, 2.));

    return uv = fract(uv * Rotate2D(PI/2 * rot));
}

vec2 PatternTruchet(vec2 uv, float i){
    i = fract((i-0.5)*2.);

    if(i > 0.75){
        uv = vec2(1.0) - uv;
    }else if(i > 0.5){
        uv = vec2(1.0 - uv.x, uv.y);
    }else if(i > 0.25){
        uv = 1.0 - vec2(1.0 - uv.x, uv.y);
    }
    return uv;
}

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    vec3 color = vec3(0.0);

    uv *= 10.;
    //uv *= abs(sin(u_time*0.2))*5.;
    //uv.x += u_time*3.;

    vec2 ipos = floor(uv);
    vec2 fpos = fract(uv*Rotate2D(u_time*0.5));

    vec2 tiles = PatternTruchet(fpos, Random2D(ipos));

    float pipes = smoothstep(tiles.x-0.3, tiles.x, tiles.y) - smoothstep(tiles.x, tiles.x+0.3, tiles.y);
    float circles = (step(length(tiles), 0.6) -
        step(length(tiles), 0.4) ) +
        (step(length(tiles-vec2(1.)), 0.6) - step(length(tiles-vec2(1.)), 0.4) );
    float triangles = step(tiles.x, tiles.y);

    color = vec3(pipes);
    color = vec3(circles);
    //color = vec3(triangles);


    fragColor = vec4(color, 1.0);
}
