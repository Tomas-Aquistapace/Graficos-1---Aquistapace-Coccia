#ifndef GAME_H
#define GAME_H

#include "GameBase/GameBase.h"

namespace Engine
{

	class Game : GameBase
	{
	public:
		Game();
		~Game();

		void Start();
		void Play();
		void Update();
		void End();
	};

}

#endif;