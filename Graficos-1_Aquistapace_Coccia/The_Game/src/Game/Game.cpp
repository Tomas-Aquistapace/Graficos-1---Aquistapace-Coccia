#include "Game.h"
#include <iostream>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_triangle1 = NULL;
		_quad1 = NULL;
	}

	Game::~Game()
	{
		if (_triangle1 != NULL)
			delete _triangle1;
		if (_quad1 != NULL)
			delete _quad1;
	}

	void Game::Start()
	{
		StartEngine(850, 420, "Ventana");

		_triangle1 = new Shape(GetRenderer());
		_triangle1->InitShape(TypeOfShape::Triangle);
		//_quad1 = new Shape(GetRenderer());
		//_quad1->InitShape(TypeOfShape::Quad);
	}
	
	void Game::Play()
	{
		UpdateEngine();
	}

	void Game::Update()
	{
		_triangle1->SetPosition(_triangle1->_transform.position.x + _speed, _triangle1->_transform.position.y, _triangle1->_transform.position.z);
		_triangle1->SetRotationZ(_triangle1->_transform.rotation.z + 0.1f);
		
		_triangle1->Draw();
		//_quad1->Draw();
	}

	void Game::End()
	{
		EndEngine();
	}
}