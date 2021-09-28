#include "Entity.h"
#include "glm/gtc/matrix_transform.hpp"

namespace Engine
{
	Entity::Entity(Renderer* renderer)
	{
		_renderer = renderer;

		SetPosition(0,0,0);
		SetRotation(0,0,0);
		SetScale(1,1,1);
	}

	Entity::~Entity()
	{

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
		_transform.rotation = { x, y, z };
		_generalMatrix.rotateX = glm::rotate(glm::mat4(1.0f), glm::radians(x), glm::vec3(1.0f, 0.0f, 0.0f));
		_generalMatrix.rotateY = glm::rotate(glm::mat4(1.0f), glm::radians(y), glm::vec3(0.0f, 1.0f, 0.0f));
		_generalMatrix.rotateZ = glm::rotate(glm::mat4(1.0f), glm::radians(z), glm::vec3(0.0f, 0.0f, 1.0f));
		UpdateMatrix();
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
}