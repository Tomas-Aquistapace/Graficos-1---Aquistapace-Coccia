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
		_tile = NULL;
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
		if (_tile != NULL)
			delete _tile;
		if (_tileMap != NULL)
			delete _tileMap;
	}

	void Game::Start()
	{
		StartEngine(1920, 1080, "Graficos 1 - Final Aquistapace");
		srand(time(NULL));

		SetCamera(CameraType::Perspective, 0.1f, 100.0f);
		SetCameraPosition(0, 0, 10);

		// --------------------------------
		
		_wall1 = new Sprite(GetRenderer());
		_wall1->InitTexture();
		_wall1->ImportTexture("res/wall.jpg");
		_wall1->SetPosition(0, 1.2, 0);
		_wall1->SetStaticState(true);
		GetCollisionManager()->AddNewObject(_wall1);
		
		// --------------------------------

		_wall2 = new Sprite(GetRenderer());
		_wall2->InitTexture();
		_wall2->ImportTexture("res/wall.jpg");
		_wall2->SetPosition(0, -1.2, 0);
		_wall2->SetStaticState(true);
		GetCollisionManager()->AddNewObject(_wall2);
		
		// --------------------------------
		
		_box = new Sprite(GetRenderer());
		_box->InitTexture();
		_box->ImportTexture("res/crate1_diffuse.png");
		_box->SetPosition(0, 0, 0);
		GetCollisionManager()->AddNewObject(_box);

		// --------------------------------

		_roboBob = new Player(GetRenderer(), ivec2(9,5), 2);
		_roboBob->GetAnimation()->AddFrame(0.5, 0, 7);

		_roboBob->InitTexture();
		_roboBob->ImportTexture("res/character_robot_sheet.png");
		_roboBob->SetPosition(-1.8, 0, 0);
		GetCollisionManager()->AddNewObject(_roboBob);

		// --------------------------------
		const char* path = "res/Mega_Man_X_Sigma_Stage_3_Tileset.png";
		vec3 startPosition = vec3(-3, -3, 0);
		vec2 startScale = vec2(0.5f, 0.5f);

		_tileMap = new TileMap(GetRenderer());
		_tileMap->InitTileMap(startPosition, path, ivec2(16, 17), _tileModuleMatrix, startScale);

		//vec3 startPosition, const char* path, const ivec2& tileDimensions, TileModule** tileModule, vec2 tileScale

		// --------------------------------

		//_tile = new Tile(GetRenderer(), ivec2(16, 17), 204);
		////_tile = new Tile(GetRenderer(), ivec2(9, 9));
		//_tile->InitTexture();
		////_tile->ImportTexture("res/tilesetFuture.png");
		//_tile->ImportTexture("res/Mega_Man_X_Sigma_Stage_3_Tileset.png");
		//_tile->SetPosition(0, 0, 0);
		//_tile->SetScale(0.5f, 0.5f, 0.5f);

		//_tile->GetAnimation()->AddFrame(0.5f, 7, 8);
	}
	
	void Game::Play()
	{
		UpdateEngine(0.0f, 0.0f, 0.0f, 1);
	}

	void Game::Update(float deltaTime)
	{
		_tileMap->DrawTileMap();

		_roboBob->Move(deltaTime);

		//GetCollisionManager()->CheckAllCollisions();

		//_wall1->Draw();
		//_wall2->Draw();
		//_box->Draw();
		

		//_tile->DrawTile();

		//_tile->GetAnimation()->UpdateFrame(deltaTime);
		//_tile->DrawAnimation();
	}

	void Game::End()
	{
		EndEngine();
	}
}