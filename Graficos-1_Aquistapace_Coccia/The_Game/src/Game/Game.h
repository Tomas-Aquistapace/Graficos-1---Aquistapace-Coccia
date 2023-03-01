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
		Sprite* _wall1;
		Sprite* _wall2;
		Sprite* _box;
		Coin* _coin;

		Player* _roboBob;
		TileMap* _tileMap;

		vector<vector<TileModule>> _tileModuleMatrix
		{
			{{70, true}, {67, true}, {68, true}, {68, true}, {69, true}, {216, true}},
			{{64, true}, {108, false}, {108, false}, {108, false}, {108, false}, {64, true}},
			{{66, true}, {108, false}, {108, false}, {108, false}, {108, false}, {66, true}},
			{{65, true}, {108, false}, {108, false}, {108, false}, {108, false}, {65, true}},
			{{216, true}, {108, false}, {108, false}, {108, false}, {108, false}, {72, true}},
			{{64, true}, {108, false}, {108, false}, {108, false}, {108, false}, {64, true}},
			{{65, true}, {108, false}, {108, false}, {108, false}, {108, false}, {65, true}}
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