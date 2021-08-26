#include "Renderer.h"
#include "GLFW/glfw3.h"

namespace Renderer_name
{
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
}