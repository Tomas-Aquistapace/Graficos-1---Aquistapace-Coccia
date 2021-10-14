#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
in vec3 color;
out vec4 vColour;

void main()
{
	gl_Position = projection * view * model * position;
	vColour = vec4(color, 1.0f);
}