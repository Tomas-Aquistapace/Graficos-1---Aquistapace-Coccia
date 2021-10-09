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
		_triangle1->SetColor(ENTITY_COLOR::BLUE);

		_quad1 = new Shape(GetRenderer());
		_quad1->InitShape(TypeOfShape::Quad);
		_quad1->SetPosition(-0.5f, 0.5f, 0);
		_quad1->SetColor(0.25f, 0.25f, 0.25f);
	}
	
	void Game::Play()
	{
		UpdateEngine(0.5f, 0.5f, 0.5f, 1);
	}

	void Game::Update()
	{
		//_triangle1->SetPosition(_triangle1->_transform.position.x + _speed, _triangle1->_transform.position.y, _triangle1->_transform.position.z);
		//_triangle1->SetRotationZ(_triangle1->_transform.rotation.z + 0.05f);
		
		//_quad1->SetRotationZ(_quad1->_transform.rotation.z - 0.1f);
		//_quad1->SetScale(_quad1->_transform.scale.x, _quad1->_transform.scale.y + 0.0001f, _quad1->_transform.scale.z + 0.0001f);

		if (Input::GetKey(Keycode::W))
		{
			_quad1->SetPosition(_quad1->_transform.position.x, _quad1->_transform.position.y + _speed, _quad1->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			_quad1->SetPosition(_quad1->_transform.position.x, _quad1->_transform.position.y - _speed, _quad1->_transform.position.z);
		}

		if (Input::GetKey(Keycode::A))
		{
			_quad1->SetPosition(_quad1->_transform.position.x - _speed, _quad1->_transform.position.y , _quad1->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			_quad1->SetPosition(_quad1->_transform.position.x + _speed, _quad1->_transform.position.y , _quad1->_transform.position.z);
		}
		_triangle1->Draw();
		_quad1->Draw();


	}

	void Game::End()
	{
		EndEngine();
	}
}