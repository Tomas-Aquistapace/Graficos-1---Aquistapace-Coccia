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

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		_window->CreateWindow(width, height, windowName, NULL);
		_window->InitWindow();

		_renderer->InitGlew();

		_renderer->CreateBuffer();
		_renderer->CreateShader();
	}

	void GameBase::UpdateEngine()
	{
		while (!_window->WindowShouldClose())
		{
			/* Render here */
			_window->ClearWindow(0.0f, 0.0f, 0.0f, 1);
			_renderer->DrawRenderer();
			
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