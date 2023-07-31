#ifndef GAME_H
#define GAME_H

#include "GameBase/GameBase.h"
#include "../Objects/Player.h"
#include "../Objects/Coin.h"

namespace Engine
{
	class Game : public GameBase
	{
	private:
		Coin* _coin;

		Player* _link;
		TileMap* _tileMap;

		const int grass_C_L = 363;
		const int grass_C_C = 364;
		const int grass_C_R = 365;

		const int grass_S_L = 387;
		const int grass_S_C = 388;
		const int grass_S_R = 389;

		const int grass_I_L = 339;
		const int grass_I_C = 340;
		const int grass_I_R = 341;

		const int grass_H_S = 414;
		const int grass_H_I = 390;

		const int tree_I_L = 392;
		const int tree_I_R = 393;
		const int tree_S_L = 416;
		const int tree_S_R = 417;

		const int swamp = 325;

		const int rock = 400;

		vector<vector<TileModule>> _tileZeldaModuleMatrix
		{
			{{grass_I_L, false}, {grass_I_C, false}, {grass_I_C, false}, {grass_I_C, false}, {grass_I_C, false}, {grass_I_C, false}, {grass_I_C, false}, {grass_I_R, false}},
			{{grass_C_L, false}, {grass_C_C, false}, {grass_C_C, false}, {rock, true},       {grass_C_C, false}, {grass_H_I, false}, {grass_S_C, false}, {grass_S_R, false}},
			{{grass_C_L, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_R, false}, {swamp, true},      {swamp, true}},
			{{grass_C_L, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_R, false}, {swamp, true},      {swamp, true}},
			{{grass_C_L, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_H_S, false}, {grass_I_C, false}, {grass_I_R, false}},
			{{grass_C_L, false}, {grass_C_C, false}, {tree_I_L, true},   {tree_I_R, true},   {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_R, false}},
			{{grass_C_L, false}, {grass_C_C, false}, {tree_S_L, true},   {tree_S_R, true},   {grass_C_C, false}, {grass_C_C, false}, {grass_C_C, false}, {grass_C_R, false}},
			{{grass_S_L, false}, {grass_S_C, false}, {grass_S_C, false}, {grass_S_C, false}, {grass_S_C, false}, {grass_S_C, false}, {grass_S_C, false}, {grass_S_R, false}}
		};

	public:
		Game();
		~Game();

		void Start();
		void Play();
		void Update(float deltaTime) override;
		void End();
	};
}

#endif;