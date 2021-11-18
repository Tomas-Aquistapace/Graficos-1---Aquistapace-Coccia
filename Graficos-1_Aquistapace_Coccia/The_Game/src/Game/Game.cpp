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
		
		_testSprite = NULL;
		_testAnimation = NULL;
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
		if (_testAnimation != NULL)
			delete _testAnimation;
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

		_testSprite = new Sprite(GetRenderer());
		_testSprite->InitTexture();
		_testSprite->ImportTexture("res/character_robot_sheet.png");
		_testSprite->SetPosition(0, 0, 0);
		GetCollisionManager()->AddNewObject(_testSprite);

		_testAnimation = new Animation();
		_testAnimation->InitSpriteSheet(_testSprite,ivec2(9,5));
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}
	void Game::Update(float deltaTime)
	{
		if (Input::GetKey(Keycode::W))
		{
			_bob->SetPosition(_bob->_transform.position.x, _bob->_transform.position.y + (_speed * deltaTime), _bob->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			_bob->SetPosition(_bob->_transform.position.x, _bob->_transform.position.y - (_speed * deltaTime), _bob->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::A))
		{
			_bob->SetPosition(_bob->_transform.position.x - (_speed * deltaTime), _bob->_transform.position.y, _bob->_transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			_bob->SetPosition(_bob->_transform.position.x + (_speed * deltaTime), _bob->_transform.position.y, _bob->_transform.position.z);
		}

		GetCollisionManager()->CheckAllCollisions();

		_wall1->Draw();
		_wall2->Draw();
		_box->Draw();
		_testSprite->DrawAnimation(_testAnimation->GetUVs(0));
		_bob->Draw();
	}

	void Game::End()
	{
		EndEngine();
	}
}