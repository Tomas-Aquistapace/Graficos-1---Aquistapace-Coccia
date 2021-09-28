#include "Entity.h"
#include "glm/gtc/matrix_transform.hpp"

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
		_transform.position.x = x;
		_transform.position.y = y;
		_transform.position.z = z;

		_generalMatrix.translate = glm::translate(glm::mat4(1.0f), _transform.position);
		UpdateMatrix();
	}

	void Entity::SetRotation(float x, float y, float z)
	{
		SetRotationX(x);
		SetRotationY(y);
		SetRotationZ(z);
	}

	void Entity::SetScale(float x, float y, float z) 
	{
		_transform.scale.x = x;
		_transform.scale.y = y;
		_transform.scale.z = z;

		_generalMatrix.scale = glm::scale(glm::mat4(1.0f), _transform.scale);
		UpdateMatrix();
	}

	void Entity::SetRotationX(float x)
	{
		_transform.rotation.x = x;
		_generalMatrix.rotateX = glm::rotate(glm::mat4(1.0f), glm::radians(x), glm::vec3(1.0f, 0.0f, 0.0f));
		UpdateMatrix();
	}
	
	void Entity::SetRotationY(float y)
	{
		_transform.rotation.y = y;
		_generalMatrix.rotateY = glm::rotate(glm::mat4(1.0f), glm::radians(y), glm::vec3(0.0f, 1.0f, 0.0f));
		UpdateMatrix();
	}
	
	void Entity::SetRotationZ(float z)
	{
		_transform.rotation.z = z;
		_generalMatrix.rotateZ = glm::rotate(glm::mat4(1.0f), glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
		UpdateMatrix();
	}

	// --------------------------------

	// Se utiliza para poder updatear la matris "model" que controla todas posiciones y datos de la figura
	void Entity::UpdateMatrix() 
	{
		_generalMatrix.model = 
			_generalMatrix.translate * 
			_generalMatrix.rotateX * 
			_generalMatrix.rotateY *
			_generalMatrix.rotateZ * 
			_generalMatrix.scale;
	}

	// --------------------------------

	void Entity::SetColor(ENTITY_COLOR color)
	{
		switch (color)
		{
		case ENTITY_COLOR::WHITE:
			break;
		case ENTITY_COLOR::BLACK:
			break;
		case ENTITY_COLOR::BLUE:
			break;
		case ENTITY_COLOR::RED:
			break;
		case ENTITY_COLOR::GREEN:
			break;
		case ENTITY_COLOR::GRAY:
			break;
		case ENTITY_COLOR::YELLOW:
			break;
		case ENTITY_COLOR::ORANGE:
			break;
		}
	}
}