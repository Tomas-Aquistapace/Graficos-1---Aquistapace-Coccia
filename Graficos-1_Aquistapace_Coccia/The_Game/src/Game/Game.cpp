#include "Game.h"
#include <iostream>
#include <time.h>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_bob = NULL;
		_wall1 = NULL;
		_wall2 = NULL;
		_box = NULL;
		
		_roboBob = NULL;
		_roboBobAnimation = NULL;
	}

	Game::~Game()
	{
		if (_bob != NULL)
			delete _bob;
		if (_wall1 != NULL)
			delete _wall1;
		if (_wall2 != NULL)
			delete _wall2;
		if (_box != NULL)
			delete _box;
		if (_roboBobAnimation != NULL)
			delete _roboBobAnimation;
	}

	void Game::Start()
	{
		StartEngine(850, 420, "Ventana");
		srand(time(NULL));

		SetCamera(CameraType::Perspective, 0.1f, 100.0f);

		_bob = new Player(GetRenderer());
		_bob->InitTexture();
		_bob->ImportTexture("res/BOB-ESPONJA-1-22.png");
		_bob->SetPosition(-1.8, 0, 0);
		GetCollisionManager()->AddNewObject(_bob);

		_wall1 = new Sprite(GetRenderer());
		_wall1->InitTexture();
		_wall1->ImportTexture("res/wall.jpg");
		_wall1->SetPosition(0, 1.2, 0);
		_wall1->SetStaticState(true);
		GetCollisionManager()->AddNewObject(_wall1);
		
		_wall2 = new Sprite(GetRenderer());
		_wall2->InitTexture();
		_wall2->ImportTexture("res/wall.jpg");
		_wall2->SetPosition(0, -1.2, 0);
		_wall2->SetStaticState(true);
		GetCollisionManager()->AddNewObject(_wall2);
		
		_box = new Sprite(GetRenderer());
		_box->InitTexture();
		_box->ImportTexture("res/crate1_diffuse.png");
		_box->SetPosition(0, 0, 0);
		GetCollisionManager()->AddNewObject(_box);

		_roboBob = new Sprite(GetRenderer());
		_roboBob->InitTexture();
		_roboBob->ImportTexture("res/character_robot_sheet.png");
		_roboBob->SetPosition(0, 0, 0);
		GetCollisionManager()->AddNewObject(_roboBob);

		_roboBobAnimation = new Animation();
		_roboBobAnimation->InitSpriteSheet(_roboBob,ivec2(9,5));
		_roboBobAnimation->AddFrame(0.1, 0, 7);
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}
	void Game::Update(float deltaTime)
	{
		if (Input::GetKey(Keycode::W))
		{
			_roboBob->SetPosition(_roboBob->_transform.position.x, _roboBob->_transform.position.y + (_speed * deltaTime), _roboBob->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			_roboBob->SetPosition(_roboBob->_transform.position.x, _roboBob->_transform.position.y - (_speed * deltaTime), _roboBob->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::A))
		{
			_roboBobAnimation->UpdateFrame(deltaTime);
			_roboBob->DrawAnimation(_roboBobAnimation->GetUVs(_roboBobAnimation->GetCurrentFrame()));
			_roboBob->SetRotationY(180);

			_roboBob->SetPosition(_roboBob->_transform.position.x - (_speed * deltaTime), _roboBob->_transform.position.y, _roboBob->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			_roboBobAnimation->UpdateFrame(deltaTime);
			_roboBob->DrawAnimation(_roboBobAnimation->GetUVs(_roboBobAnimation->GetCurrentFrame()));
			_roboBob->SetRotationY(0);

			_roboBob->SetPosition(_roboBob->_transform.position.x + (_speed * deltaTime), _roboBob->_transform.position.y, _roboBob->_transform.position.z);
		}
		else
		{
			_roboBobAnimation->UpdateFrame(deltaTime);
			_roboBob->DrawAnimation(_roboBobAnimation->GetUVs(36));
		}
		GetCollisionManager()->CheckAllCollisions();

		_wall1->Draw();
		_wall2->Draw();
		//_box->Draw();
		
		_bob->Draw();
	}

	void Game::End()
	{
		EndEngine();
	}
}