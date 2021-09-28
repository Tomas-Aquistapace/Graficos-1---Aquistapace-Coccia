#ifndef GAME_H
#define GAME_H

#include "GameBase/GameBase.h"

namespace Engine
{
	class Game : public GameBase
	{
	private:
		Shape* _triangle1;
		Shape* _quad1;

		float _speed = 0.0001f;

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