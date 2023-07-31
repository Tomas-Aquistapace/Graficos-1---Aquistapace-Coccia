#include "Game.h"
#include <iostream>
#include <time.h>

namespace Engine
{
	Game::Game(): GameBase()
	{
		_link = NULL;
		_coin = NULL;
		_tileMap = NULL;
	}

	Game::~Game()
	{
		if (_link != NULL)
			delete _link;
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
		cout << "Lodaing _coin" << endl;

		_coin = new Coin(GetRenderer());
		_coin->ImportTexture("res/Coin_Master.png");
		_coin->SetPosition(0, 0, 0);

		_coin->SetTag("coin");
		_coin->AddAnimation("rotation", ivec2(8, 1), 0.5f, 0, 7);

		GetCollisionManager()->AddNewObject(_coin);

		cout << "-> Loaded _coin" << endl;
		// --------------------------------
		cout << "Lodaing _link" << endl;

		_link = new Player(GetRenderer(), 2);
		_link->ImportTexture("res/Links Links Awakening sprite sheet.png");

		_link->SetTag("player");

		_link->AddAnimation("walk_right", ivec2(10, 16), 0.5f, 150, 151);
		_link->AddAnimation("walk_up", ivec2(10, 16), 0.5f, 152, 153);
		_link->AddAnimation("walk_left", ivec2(10, 16), 0.5f, 154, 155);
		_link->AddAnimation("walk_down", ivec2(10, 16), 0.5f, 156, 157);
		_link->AddAnimation("idle", ivec2(10, 16), 1, 158, 158);

		_link->SetPosition(-1.8, 0, 0);
		GetCollisionManager()->AddNewObject(_link);

		cout << "-> Loaded _link" << endl;
		// --------------------------------
		cout << "Lodaing _tileMap" << endl;

		const char* path = "res/Game Boy GBC - The Legend of Zelda Links Awakening DX - Overworld Tileset.png";
		vec3 startPosition = vec3(-3, -3, 0);
		vec2 tileScale = vec2(1.2, 1.2);

		_tileMap = new TileMap(GetRenderer());
		_tileMap->InitTileMap(startPosition, path, ivec2(24, 25), _tileZeldaModuleMatrix, tileScale);

		cout << "-> Loaded _tileMap" << endl;
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}

	void Game::Update(float deltaTime)
	{
		_tileMap->DrawTileMap();

		_link->Move(deltaTime);
		_coin->DrawCoin(deltaTime);

		_tileMap->CheckTileCollisions(_link);
		GetCollisionManager()->CheckAllCollisions();
	}

	void Game::End()
	{
		EndEngine();
	}
}