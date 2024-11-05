#version 460

#ifdef GL
precision mediump float;
#endif

layout(location = 0) out vec4 fragColor;

uniform float u_time;
uniform vec2 u_resolution;
uniform vec2 u_mouse;

float BandSimple(float uvAxis, float size, float blur){
    float band = smoothstep(size + blur, size, abs(uvAxis.x));
    return band;
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

float Rand2D(vec2 uv){
    return fract(sin(dot(uv.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

float Rand2D2(vec2 uv){
    float random;
    return random;
}

vec3 FarLands(vec2 uv, vec3 color){
    uv *= 20.0;
    vec2 uvMouse = u_mouse;
    vec2 ipos = floor(uv+uvMouse)*uvMouse;
    return color *= Rand2D(ipos);
}

vec3 PixelNoise(vec2 uv, vec3 color, float scale){
    uv *= scale;
    vec2 ipos = floor(uv);
    return color *= Rand2D(ipos);
}

vec3 DotsStaircase(vec2 uv, vec3 color, int recursionSteps){
    for(int i = 0; i < recursionSteps; i++){
        color = round(PixelNoise(uv+floor(u_time), color, 1.0));
        uv = fract(uv*10.0);
        color *= smoothstep(0.1, 0.2, length(uv-0.5));
    }
    return color;
}

float Rand(float seed){
    return fract(sin(seed)*100000.);
}

vec3 dotTiles(vec2 uv0, vec3 color){
    color = round(PixelNoise(uv0, color, 1.0));
    uv0 = fract(uv0*10.0);
    return color *= smoothstep(0.1, 0.2, length(uv0-0.5));
}

vec3 idkWhatToCallThisOne(vec2 uv, vec3 color){
    vec2 uvMouse = u_mouse/u_resolution;
    vec2 uv0 = uv;

    float scale = 20.0;
    uv *= scale;

    for(int i = 1; i < 2*scale+1; i++){
        uv.x -= step(i-1, mod(uv.y, 2.0*scale)) * u_time * (Rand(round(uv0.y*2*scale)))/4.;
    }
    //uv.y += step(1.0, mod(uv.x, 2.0))*u_time;

    vec2 uv1 = uv;
    uv = fract(uv);

    uv0 = gl_FragCoord.xy / u_resolution;

    for(int i = 0; i < 9; i++){
        //color -= Rectangle(uv-0.5, vec2((floor((i+1)*uvMouse.x*6.0)/8.0 - 0.1*step(0.1, u_mouse.x))*(uv0.y), 0.2), vec4(0.01));
        //color -= Rectangle(uv-0.5, vec2((i+1)/5. , 0.2), vec4(0.01))*round(PixelNoise(uv0+round(uvMouse.x*scale), color, scale));
        color -= Rectangle(uv-0.5, vec2(0.1 + 0.2*step(1.0, mod(uv1.x, (i+1.0)*round(uvMouse.x*6)/20.0)) + 0.2*step(1.0, mod(-uv1.x, (i+1.0)*round(uvMouse.x*4)/4)), 0.2), vec4(0.01));
    }
    return color;
}

void main(){
    vec2 uv = (2.0 * gl_FragCoord.xy - u_resolution) / u_resolution.y;
    vec3 color = vec3(1.0);


    fragColor = vec4(color, 1.0);

}
