#ifndef GAME_H
#define GAME_H

#include "GameBase/GameBase.h"

namespace Engine
{
	class Game : GameBase
	{
	private:
		Shape* _triangle1;
		Shape* _quad1;

	public:
		Game();
		~Game();

		void Start();
		void Play();
		void Update() override;
		void End();
	};
}

#endif;