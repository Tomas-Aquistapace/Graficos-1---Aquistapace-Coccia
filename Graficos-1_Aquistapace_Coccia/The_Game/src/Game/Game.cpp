#include "Game.h"
#include <iostream>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_triangle1 = NULL;
	}

	Game::~Game()
	{
		if (_triangle1 != NULL)
			delete _triangle1;
	}

	void Game::Start()
	{
		StartEngine(850, 420, "Ventana");

		_triangle1 = new Shape(GetRenderer());
		_triangle1->InitShape(TypeOfShape::Triangle);
	}
	
	void Game::Play()
	{
		UpdateEngine();
	}

	void Game::Update()
	{
		_triangle1->Draw();
	}

	void Game::End()
	{
		EndEngine();
	}
}