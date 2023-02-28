#ifndef PLAYER_H
#define PLAYER_H

#include "GameBase/GameBase.h"

namespace Engine
{
	class Player : public Sprite
	{
		float _speed;

	public:
		Player(Renderer* renderer, float speed);
		~Player();

		void Move(float deltaTime);
		void TriggerCollision(Entity* other) override;
	};
}

#endif