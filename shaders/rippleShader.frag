// attributes from vertShader.vert
in vec4 vColor;
in vec2 vTexCoord;

// uniforms
uniform sampler2D uTexture;
uniform float uTime;

out vec4 fragColor;

void main() {
	float coef = sin(gl_FragCoord.y * 0.1 + 1 * uTime);
	vec2 localCoord = vTexCoord;
	localCoord.y +=  coef * 0.03;
	fragColor = vColor * texture2D(uTexture, localCoord);
}
