#include "Player.h"
#include <iostream>

namespace Engine
{
	Player::Player(Renderer* renderer, float speed) : Sprite(renderer)
	{
		_speed = speed;

		_points = 0;
	}
	
	Player::~Player()
	{

	}

	void Player::Move(float deltaTime)
	{
		if (Input::GetKey(Keycode::W))
		{
			DrawAnimation("walk_up", deltaTime);
			//SetRotationY(180);

			SetPosition(_transform.position.x, _transform.position.y + (_speed * deltaTime), _transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			DrawAnimation("walk_down", deltaTime);
			//SetRotationY(0);

			SetPosition(_transform.position.x, _transform.position.y - (_speed * deltaTime), _transform.position.z);
		}
		else if (Input::GetKey(Keycode::A))
		{
			DrawAnimation("walk_left", deltaTime);
			//SetRotationY(180);
		
			SetPosition(_transform.position.x - (_speed * deltaTime), _transform.position.y, _transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			DrawAnimation("walk_right", deltaTime);
			//SetRotationY(0);
		
			SetPosition(_transform.position.x + (_speed * deltaTime), _transform.position.y, _transform.position.z);
		}
		else
		{
			DrawAnimation("idle", deltaTime);
		}
	}

	void Player::TriggerCollision(Entity* other)
	{
		//if (!other->GetStaticState())
		//{
		//	glm::vec3 newPos = _transform.position;
		//	ReturnToPrevPosition();
		//	newPos -= _transform.position;
		//
		//	other->SetPosition(other->_transform.position + newPos);
		//}
		//else
		//{
		//	ReturnToPrevPosition();
		//}

		if (other != NULL)
		{
			if (other->GetTag() == "coin")
			{
				other->SetColliderState(false);

				_points++;

				cout << "Player points: " << _points << endl;
			}
			else
			{
				ReturnToPrevPosition();
			}
		}
	}
}