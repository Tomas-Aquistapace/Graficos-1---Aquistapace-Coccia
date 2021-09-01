#include "GameBase.h"
#include <iostream>
#include "GLFW/glfw3.h"

namespace Engine
{
	GameBase::GameBase()
	{
		_window = new Windowuwu();
		_renderer = new Renderer();
	}

	GameBase::~GameBase() 
	{
		if (_window != NULL)
			delete _window;
		if (_renderer != NULL)
			delete _renderer;
	}

	int GameBase::StartEngine(int width, int height, const char* windowName) 
	{
		if (!glfwInit())
			return -1;

		_window->CreateWindow(width, height, windowName, NULL);
		_window->InitWindow();
	}

	void GameBase::UpdateEngine()
	{
		while (!_window->WindowShouldClose())
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			_window->SwapBuffers();

			/* Poll for and process events */
			glfwPollEvents();
		}
	}
	
	void GameBase::EndEngine()
	{
		glfwTerminate();
	}
}