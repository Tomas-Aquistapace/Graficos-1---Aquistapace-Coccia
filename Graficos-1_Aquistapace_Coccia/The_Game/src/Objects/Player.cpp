#include "Player.h"

namespace Engine
{
	Player::Player(Renderer* renderer, float speed) : Sprite(renderer)
	{
		_speed = speed;
	}
	
	Player::~Player()
	{

	}

	void Player::Move(float deltaTime)
	{
		if (Input::GetKey(Keycode::W))
		{
			//GetAnimation("walk")->UpdateFrame(deltaTime);
			DrawAnimation("walk", deltaTime);
			SetRotationY(180);

			SetPosition(_transform.position.x, _transform.position.y + (_speed * deltaTime), _transform.position.z);
		}
		else if (Input::GetKey(Keycode::S))
		{
			//GetAnimation("walk")->UpdateFrame(deltaTime);
			DrawAnimation("walk", deltaTime);
			SetRotationY(0);

			SetPosition(_transform.position.x, _transform.position.y - (_speed * deltaTime), _transform.position.z);
		}
		else if (Input::GetKey(Keycode::A))
		{
			//GetAnimation("walk")->UpdateFrame(deltaTime);
			DrawAnimation("walk", deltaTime);
			SetRotationY(180);
		
			SetPosition(_transform.position.x - (_speed * deltaTime), _transform.position.y, _transform.position.z);
		}
		else if (Input::GetKey(Keycode::D))
		{
			//GetAnimation("walk")->UpdateFrame(deltaTime);
			DrawAnimation("walk", deltaTime);
			SetRotationY(0);
		
			SetPosition(_transform.position.x + (_speed * deltaTime), _transform.position.y, _transform.position.z);
		}
		else
		{
			//DrawFrame(36);
			//GetAnimation("idle")->UpdateFrame(deltaTime);
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
		ReturnToPrevPosition();
	}
}