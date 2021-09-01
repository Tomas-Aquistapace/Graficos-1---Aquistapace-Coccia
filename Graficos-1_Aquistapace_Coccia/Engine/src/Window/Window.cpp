#include "Window.h"
#include "iostream"
#include "GLFW/glfw3.h"

namespace Engine
{
	Windowuwu::Windowuwu()
	{

	}

	Windowuwu::~Windowuwu()
	{

	}

	int Windowuwu::CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor)
	{
		_window = glfwCreateWindow(width, height, title, monitor, NULL);

		if (!_window)
		{
			std::cout << "Error al iniciar la ventana" << std::endl;
			return 0;
		}
		return 1;
	}

	void Windowuwu::InitWindow()
	{
		glfwMakeContextCurrent(_window);
	}

	void Windowuwu::DestroyWindow()
	{
		glfwDestroyWindow(_window);
	}

	int Windowuwu::WindowShouldClose()
	{
		return glfwWindowShouldClose(_window);
	}

	void Windowuwu::SwapBuffers()
	{
		glfwSwapBuffers(_window);
	}

	void Windowuwu::ClearWindow(float r, float g, float b, float a)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, a);
	}

	GLFWwindow* Windowuwu::ReturnWindow()
	{
		return _window;
	}
}