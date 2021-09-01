#include "Game.h"
#include <iostream>

namespace Engine
{

	Game::Game(): GameBase()
	{
		
	}

	Game::~Game()
	{

	}

	void Game::Start()
	{
		StartEngine(850, 420, "Ventana");
	}
	
	void Game::Play()
	{
		UpdateEngine();
	}

	void Game::Update()
	{
		
	}

	void Game::End()
	{
		EndEngine();
	}

}