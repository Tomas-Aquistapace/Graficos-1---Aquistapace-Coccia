#include "Game.h"
#include <iostream>
#include <time.h>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_sprite = NULL;
		_sprite2 = NULL;
	}

	Game::~Game()
	{
		if (_sprite != NULL)
			delete _sprite;
		if (_sprite2 != NULL)
			delete _sprite2;
	}

	void Game::Start()
	{
		StartEngine(850, 420, "Ventana");
		srand(time(NULL));

		SetCamera(CameraType::Perspective, 0.1f, 100.0f);

		_sprite = new Sprite(GetRenderer());
		_sprite->InitTexture();
		_sprite->ImportTexture("res/BOB-ESPONJA-1-22.png");
		_sprite->SetPosition(-1.8, 0, 0);

		_sprite2 = new Sprite(GetRenderer());
		_sprite2->InitTexture();
		_sprite2->ImportTexture("res/wall.png");
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}

	void Game::Update(float deltaTime)
	{		
		if (Input::GetKey(Keycode::W))
		{
			_sprite->SetPosition(_sprite->_transform.position.x, _sprite->_transform.position.y + (_speed * deltaTime), _sprite->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			_sprite->SetPosition(_sprite->_transform.position.x, _sprite->_transform.position.y - (_speed * deltaTime), _sprite->_transform.position.z);
		}

		if (Input::GetKey(Keycode::A))
		{
			_sprite->SetPosition(_sprite->_transform.position.x - (_speed * deltaTime), _sprite->_transform.position.y, _sprite->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			_sprite->SetPosition(_sprite->_transform.position.x + (_speed * deltaTime), _sprite->_transform.position.y, _sprite->_transform.position.z);
		}

		if (GetCollisionManager()->CheckCollision(*_sprite, *_sprite2))
		{
			std::cout << "Colisiono!" << std::endl;
		}

		_sprite2->Draw();
		_sprite->Draw();
	}

	void Game::End()
	{
		EndEngine();
	}

}