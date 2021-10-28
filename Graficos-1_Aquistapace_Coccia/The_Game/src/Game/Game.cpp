#include "Game.h"
#include <iostream>
#include <time.h>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_triangle1 = NULL;
		_quad1 = NULL;
		_sprite = NULL;
	}

	Game::~Game()
	{
		if (_triangle1 != NULL)
			delete _triangle1;
		if (_quad1 != NULL)
			delete _quad1;
		if (_sprite != NULL)
			delete _sprite;
	}

	void Game::Start()
	{
		StartEngine(850, 420, "Ventana");
		srand(time(NULL));

		SetCamera(CameraType::Perspective, 0.1f, 100.0f);

		_sprite = new Sprite(GetRenderer());
		_sprite->InitTexture();
		_sprite->ImportTexture("res/BOB-ESPONJA-1-22.png");
		
		//_triangle1 = new Shape(GetRenderer());
		//_triangle1->InitShape(TypeOfShape::Triangle);
		//_triangle1->SetColor(ENTITY_COLOR::BLUE);
		//
		//_quad1 = new Shape(GetRenderer());
		//_quad1->InitShape(TypeOfShape::Quad);
		//_quad1->SetPosition(-0.5f, 0.5f, 0);
		//_quad1->SetColor(0.25f, 0.25f, 0.25f);
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}

	void Game::Update(float deltaTime)
	{		
		if (Input::GetKey(Keycode::W))
		{
			//_quad1->SetPosition(_quad1->_transform.position.x, _quad1->_transform.position.y + (_speed * deltaTime), _quad1->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			//_quad1->SetPosition(_quad1->_transform.position.x, _quad1->_transform.position.y - (_speed * deltaTime), _quad1->_transform.position.z);
		}

		if (Input::GetKey(Keycode::A))
		{
			//_quad1->SetPosition(_quad1->_transform.position.x - (_speed * deltaTime), _quad1->_transform.position.y , _quad1->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			//_quad1->SetPosition(_quad1->_transform.position.x + (_speed * deltaTime), _quad1->_transform.position.y , _quad1->_transform.position.z);
		}
		//_triangle1->Draw();
		//_quad1->Draw();
		_sprite->Draw();
	}

	void Game::End()
	{
		EndEngine();
	}

}