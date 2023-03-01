#include "Coin.h"

namespace Engine
{
	Coin::Coin(Renderer* renderer) : Sprite(renderer)
	{
		_active = true;
	}

	Coin::~Coin()
	{

	}

	void Coin::DrawCoin(float deltaTime)
	{
		if (_active)
		{
			DrawAnimation("rotation", deltaTime);
		}
	}

	void Coin::TriggerCollision(Entity* other)
	{
		if (other != NULL)
		{
			if (other->GetTag() == "player")
			{
				_active = false;
			}
		}
	}
}