shader_type canvas_item;

uniform float scale : hint_range(0.0, 10.0) = 2.0;

void fragment() {
	vec2 distortedUV = UV;
	distortedUV.x += distortedUV.y * 0.2;
	
	vec4 pixel_color = texture(TEXTURE, distortedUV * scale);
	COLOR = pixel_color;
}
