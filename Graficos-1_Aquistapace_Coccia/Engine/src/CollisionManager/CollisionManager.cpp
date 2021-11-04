#include "CollisionManager.h"

namespace Engine
{
	//CollisionManager::CollisionManager() { }
	//
	//CollisionManager::~CollisionManager() { }

	bool CollisionManager::CheckCollision(Sprite& one, Sprite& two)
	{
		bool collisionX = one._transform.position.x + one._transform.scale.x >= two._transform.position.x &&
						  two._transform.position.x + two._transform.scale.x >= one._transform.position.x;
		
		bool collisionY = one._transform.position.y + one._transform.scale.y >= two._transform.position.y &&
						  two._transform.position.y + two._transform.scale.y >= one._transform.position.y;

		return collisionX && collisionY;
	}
	
	bool CollisionManager::CheckCollision(Shape& one, Shape& two)
	{
		bool collisionX = one._transform.position.x + one._transform.scale.x >= two._transform.position.x &&
			two._transform.position.x + two._transform.scale.x >= one._transform.position.x;
	
		bool collisionY = one._transform.position.y + one._transform.scale.y >= two._transform.position.y &&
			two._transform.position.y + two._transform.scale.y >= one._transform.position.y;

		return collisionX && collisionY;
	}
}