shader_type canvas_item;


void fragment() {
	vec4 pixel_color = texture(TEXTURE, UV);
	float brightness = (pixel_color.r + pixel_color.g + pixel_color.b) / 3.0;
	vec4 grayScale = vec4(brightness, brightness, brightness, pixel_color.a);
	COLOR = grayScale;
}
