#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "..\Export\Export.h"
#include "..\Shader\Shader.h"
#include "..\Camera\Camera.h"
#include "glm\glm\mat4x4.hpp"

namespace Engine
{
	enum class TypeOfShape {
		Triangle,
		Quad
	};

	class EXPORT_API Renderer
	{
	private:
		Shader* _shader;
		Camera* _camera;

	public:
		Renderer();
		~Renderer();
		
		int InitGlew();
		void SetVertexBuffer(int size, float* vertex, unsigned int &vao, unsigned int &vbo);
		void SetIndexBuffer(int size, unsigned int* index, unsigned int &ebo);
		void SetAtrtribs(int size, int strides, int offset);
		void CreateShader();
		void Draw(TypeOfShape shape, unsigned int& vao, unsigned int& vbo, unsigned int& ebo, float* vertex, float vertexSize, int vertexCount);
		void UpdateModel(glm::mat4 model, unsigned int updateShape);
		void StopShader();

		void SetCameraValues(CameraType type, float near, float far);
		unsigned int GetShader();
	};
}
#endif