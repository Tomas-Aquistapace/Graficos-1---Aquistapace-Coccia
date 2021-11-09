#include "Player.h"

namespace Engine
{
	Player::Player(Renderer* renderer) : Sprite(renderer)
	{

	}
	
	Player::~Player()
	{

	}

	void Player::TriggerCollision(Entity* other)
	{
		if (!other->GetStaticState())
		{
			glm::vec3 newPos = _transform.position;
			ReturnToPrevTransform();
			newPos -= _transform.position;

			other->SetPosition(other->_transform.position + newPos);
		}
		else 
		{
			ReturnToPrevTransform();
		}
	}
}