#include "GameBase.h"
#include <iostream>
#include "GLFW/glfw3.h"
#include "../Input/Input.h"

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

		Input::SetWindow(_window->ReturnWindow());

		_renderer->InitGlew();
		_renderer->CreateShader();
	}

	void GameBase::UpdateEngine(float r, float g, float b, float a)
	{
		while (!_window->WindowShouldClose())
		{
			/* Render here */
			_window->ClearWindow(r, g, b, a);
			
			Update(); // --> Aca se utiliza un metodo virtual para poder dibujar los objetos del Game.cpp

			/* Swap front and back buffers */
			_window->SwapBuffers();

			/* Poll for and process events */
			glfwPollEvents();
		}
	}
	
	void GameBase::EndEngine()
	{
		_renderer->StopShader();
		glfwTerminate();
	}

	//===========================================

	Renderer* GameBase::GetRenderer()
	{
		return _renderer;
	}
}