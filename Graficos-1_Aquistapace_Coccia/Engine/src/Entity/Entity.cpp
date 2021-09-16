#include "Entity.h"

namespace Engine
{
	Entity::Entity(Renderer* renderer)
	{
		_renderer = renderer;
	}

	Entity::~Entity()
	{
		if(_renderer != NULL)
			delete _renderer;
	}

	void Entity::SetPosition(float x, float y, float z)
	{

	}

	void Entity::SetRotation(float x, float y, float z)
	{

	}

	void Entity::SetScale(float x, float y, float z) 
	{

	}
}