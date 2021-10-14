#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include "glm\glm\mat4x4.hpp"
#include "..\Shader\Shader.h"
#include "..\Export\Export.h"

namespace Engine
{
	class EXPORT_API Camera
	{
	private:
		glm::mat4 _projection;
		glm::mat4 _view;

	public:
		Camera();
		~Camera();

		void UpdateMVP(glm::mat4 model, unsigned int shaderId);
		void UseCamera(Shader& shader, glm::mat4 trsCamera);
	};
}

#endif