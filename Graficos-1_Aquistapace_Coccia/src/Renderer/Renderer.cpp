#include "Renderer.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
namespace Renderer_name
{
	float vertex[6] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};
	unsigned int buffer;
	Renderer::Renderer()
	{
		
	}
	
	Renderer::~Renderer()
	{

	}

	int Renderer::InitGlfw()
	{

		if (!glfwInit())
		{
			return 0;
		}

		return 1;
	}
	int Renderer::InitGlew()
	{
		if (glewInit != GLEW_OK)
		{
			return 0;
		}
		return 1;
	}
	void Renderer::CreateBuffer()
	{
		//Vertex Buffers and Drawing a Triangle in OpenGL   video
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex, GL_STATIC_DRAW);


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void Renderer::DrawRenderer()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}