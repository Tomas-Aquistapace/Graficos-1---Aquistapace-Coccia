#ifndef GAME_H
#define GAME_H

#include "GameBase/GameBase.h"
#include "../Objects/Player.h"

namespace Engine
{
	class Game : public GameBase
	{
	private:
		Player* _bob;
		Sprite* _wall1;
		Sprite* _wall2;
		Sprite* _box;

		Player* _roboBob;

		TileMap* _tileMap;

		Tile* _tile;

		vector<vector<TileModule>> _tileModuleMatrix
		{
			{{70, false}, {67, false}, {68, false}, {68, false}, {69, false}, {216, false}},
			{{64, false}, {108, false}, {108, false}, {108, false}, {108, false}, {64, false}},
			{{66, false}, {108, false}, {108, false}, {108, false}, {108, false}, {66, false}},
			{{65, false}, {108, false}, {108, false}, {108, false}, {108, false}, {65, false}},
			{{216, false}, {108, false}, {108, false}, {108, false}, {108, false}, {72, false}},
			{{64, false}, {108, false}, {108, false}, {108, false}, {108, false}, {64, false}},
			{{65, false}, {108, false}, {108, false}, {108, false}, {108, false}, {65, false}}
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