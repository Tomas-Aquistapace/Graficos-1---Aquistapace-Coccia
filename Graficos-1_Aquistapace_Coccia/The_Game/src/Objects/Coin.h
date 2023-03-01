#ifndef COIN_H
#define COIN_H

#include "GameBase/GameBase.h"

namespace Engine
{
	class Coin : public Sprite
	{
	private:
		bool _active;

	public:
		Coin(Renderer* renderer);
		~Coin();

		void DrawCoin(float deltaTime);

		void TriggerCollision(Entity* other) override;
	};
}

#endif