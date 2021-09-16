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
	class EXPORT_API Entity 
	{
	private:
		struct  Transform
		{
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
			//glm::quat quatRotation;
		};

	public:
		Renderer* renderer;
		Entity();
		~Entity();

		//void SetPosition(float x, float y, float z);
		//void SetRotation(float x, float y, float z);
		//void SetScale(float x, float y, float z);
		//void SetQuat
	};
}

#endif