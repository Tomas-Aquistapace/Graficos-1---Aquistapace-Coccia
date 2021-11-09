#ifndef PLAYER_H
#define PLAYER_H

#include "GameBase/GameBase.h"

namespace Engine
{
	class Player : public Sprite
	{
	public:
		Player(Renderer* renderer);
		~Player();

		void TriggerCollision(Entity* other) override;
	};
}

#endif