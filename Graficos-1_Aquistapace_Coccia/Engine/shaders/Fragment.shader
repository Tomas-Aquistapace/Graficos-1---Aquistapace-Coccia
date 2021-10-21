#version 330 core
//in vec4 vColour;

//out vec4 colour;

out vec4 FragColor;
in vec3 outColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
	//colour = vColour;

	FragColor = texture(ourTexture, TexCoord);
}