#include "Window.h"

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
}