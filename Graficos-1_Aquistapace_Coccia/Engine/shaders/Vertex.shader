#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 model;
in vec3 color;
out vec4 vColour;

void main()
{
	gl_Position = model * position;
	vColour = vec4(color, 1.0f);
}