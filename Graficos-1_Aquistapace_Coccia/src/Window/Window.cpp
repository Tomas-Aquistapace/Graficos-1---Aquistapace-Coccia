#include "Window.h"
#include "GLFW/glfw3.h"

namespace Window_name
{
	Windowuwu::Windowuwu()
	{

	}

	Windowuwu::~Windowuwu()
	{

	}

	void Windowuwu::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor)
	{
		glfwCreateWindow(width, height, title, monitor, NULL);
	}

	void Windowuwu::DestroyWindow(GLFWwindow* window)
	{
		glfwDestroyWindow(window);
	}

	int Windowuwu::WindowShouldClose(GLFWwindow* window)
	{
		glfwWindowShouldClose(window);
	}

	void Windowuwu::SwapBuffers(GLFWwindow* window)
	{
		glfwSwapBuffers(window);
	}

	void Windowuwu::ClearWindow(float r, float g, float b, float a)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, a);
	}
}