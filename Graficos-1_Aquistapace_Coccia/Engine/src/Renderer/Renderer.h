#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "..\Export\Export.h"
#include "..\Shader\Shader.h"

namespace Engine
{
	enum TypeOfShape {
		Triangle, 
		Quad
	};

	class EXPORT_API Renderer
	{
	private:
		Shader* _shader;

	public:
		Renderer();
		~Renderer();
		
		int InitGlew();
		void SetVertexBuffer(int size, float* vertex, unsigned int &vao, unsigned int &vbo);
		void SetIndexBuffer(int size, unsigned int* index, unsigned int &ebo);
		void SetAtrtribs(int size, int strides, int offset);
		void CreateShader();
		void Draw(TypeOfShape shape, unsigned int& vao, unsigned int& vbo, unsigned int& ebo, float* vertex, float vertexSize, int vertexCount);
		void StopShader();
	};
}
#endif