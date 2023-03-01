#include "Game.h"
#include <iostream>
#include <time.h>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_roboBob = NULL;
		_wall1 = NULL;
		_wall2 = NULL;
		_box = NULL;
		_coin = NULL;
		_tileMap = NULL;
	}

	Game::~Game()
	{
		if (_roboBob != NULL)
			delete _roboBob;
		if (_wall1 != NULL)
			delete _wall1;
		if (_wall2 != NULL)
			delete _wall2;
		if (_box != NULL)
			delete _box;
		if (_coin != NULL)
			delete _coin;
		if (_tileMap != NULL)
			delete _tileMap;
	}

	void Game::Start()
	{
		StartEngine(1280, 800, "Graficos 1 - Final Aquistapace");
		srand(time(NULL));

		SetCamera(CameraType::Perspective, 0.1f, 100.0f);
		SetCameraPosition(0, 0, 15);

		// --------------------------------
		cout << "Lodaing _wall1" << endl;

		_wall1 = new Sprite(GetRenderer());
		_wall1->ImportTexture("res/wall.jpg");
		_wall1->SetPosition(0, 1.2, 0);
		_wall1->SetStaticState(true);
		//GetCollisionManager()->AddNewObject(_wall1);
		
		cout << "-> Loaded _wall1" << endl;
		// --------------------------------
		cout << "Lodaing _wall2" << endl;

		_wall2 = new Sprite(GetRenderer());
		_wall2->ImportTexture("res/wall.jpg");
		_wall2->SetPosition(0, -1.2, 0);
		_wall2->SetStaticState(true);
		//GetCollisionManager()->AddNewObject(_wall2);

		cout << "-> Loaded _wall2" << endl;
		// --------------------------------
		cout << "Lodaing _box" << endl;

		_box = new Sprite(GetRenderer());
		_box->ImportTexture("res/crate1_diffuse.png");
		_box->SetPosition(0, 0, 0);
		//GetCollisionManager()->AddNewObject(_box);

		cout << "-> Loaded _box" << endl;
		// --------------------------------
		cout << "Lodaing _coin" << endl;

		_coin = new Sprite(GetRenderer());
		_coin->ImportTexture("res/Coin_Master.png");
		_coin->SetPosition(0, 0, 0);
		//_coin->SetScale(0.5f, 0.5f, 0.5f);
		_coin->AddAnimation("rotation", ivec2(8, 1), 0.5f, 0, 7, true);

		cout << "-> Loaded _coin" << endl;
		// --------------------------------
		cout << "Lodaing _roboBob" << endl;

		_roboBob = new Player(GetRenderer(), 2);
		_roboBob->ImportTexture("res/character_robot_sheet.png");

		_roboBob->AddAnimation("walk", ivec2(9, 5), 0.5f, 0, 7, true);
		_roboBob->AddAnimation("idle", ivec2(9, 5), 1.5f, 21, 23, true);
		_roboBob->AddAnimation("punch", ivec2(9, 5), 1.5f, 9, 11, false);

		_roboBob->SetPosition(-1.8, 0, 0);
		//_roboBob->SetScale(0.5f, 0.5f, 0);
		GetCollisionManager()->AddNewObject(_roboBob);

		cout << "-> Loaded _roboBob" << endl;
		// --------------------------------
		cout << "Lodaing _tileMap" << endl;

		const char* path = "res/Mega_Man_X_Sigma_Stage_3_Tileset.png";
		vec3 startPosition = vec3(-3, -3, 0);
		vec2 startScale = vec2(1, 1);

		_tileMap = new TileMap(GetRenderer(), GetCollisionManager());
		_tileMap->InitTileMap(startPosition, path, ivec2(16, 17), _tileModuleMatrix, startScale);

		cout << "-> Loaded _tileMap" << endl;
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}

	void Game::Update(float deltaTime)
	{
		_tileMap->DrawTileMap();

		_roboBob->Move(deltaTime);

		GetCollisionManager()->CheckAllCollisions();

		//_wall1->Draw();
		//_wall2->Draw();
		//_box->Draw();
		//_coin->GetAnimation("rotation")->UpdateFrame(deltaTime);
		_coin->DrawAnimation("rotation", deltaTime);

		//_tile->GetAnimation()->UpdateFrame(deltaTime);
		//_tile->DrawAnimation();
	}

	void Game::End()
	{
		EndEngine();
	}
}