#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "..\Export\Export.h"
#include "..\Renderer\Renderer.h"
#include "glm\glm\vec3.hpp"
#include "glm\glm\mat4x4.hpp"
//#include <glm\gtc\quaternion.hpp>

namespace Engine
{
	enum class ENTITY_COLOR
	{
		WHITE, BLACK, GRAY,
		RED, GREEN, BLUE
	};

	struct Transform
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};

	struct GeneralMatrix
	{
		glm::mat4 model;
		glm::mat4 translate;
		glm::mat4 rotateX;
		glm::mat4 rotateY;
		glm::mat4 rotateZ;
		glm::mat4 scale;
	};

	class EXPORT_API Entity 
	{
	protected:
		Renderer* _renderer;
		GeneralMatrix _generalMatrix;

	public:
		Entity(Renderer* renderer);
		~Entity();

		Transform _transform;

		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		void SetScale(float x, float y, float z);

		void SetRotationX(float x);
		void SetRotationY(float y);
		void SetRotationZ(float z);

		void UpdateMatrix();

		virtual void SetColor(ENTITY_COLOR color) = 0;
		virtual void SetColor(float r, float g, float b) = 0;
	};
}

#endif