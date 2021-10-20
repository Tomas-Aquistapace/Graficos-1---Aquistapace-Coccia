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
		Sprite* _sprite;

		float _speed = 5;
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