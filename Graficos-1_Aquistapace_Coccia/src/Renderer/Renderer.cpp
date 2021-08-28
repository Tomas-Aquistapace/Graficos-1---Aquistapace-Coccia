#include "Renderer.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
namespace Renderer_name
{
	float vertex[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};
	unsigned int VBO;
	Renderer::Renderer()
	{
		glGenBuffers(1, &VBO);

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
}