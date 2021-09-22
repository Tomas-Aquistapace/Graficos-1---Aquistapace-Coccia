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
		void CreateBuffer(TypeOfShape shape,int vertexCant, unsigned int &vao, unsigned int &vbo, unsigned int &ebo, float* testvb, unsigned int indexPos);
		void CreateShader();
		void DrawRenderer(TypeOfShape shape, int vertexCant, unsigned int &vao, unsigned int &vbo, unsigned int &ebo, float* testvb, float tamVertexs, unsigned int indexPos);
		void StopShader();
	};
}
#endif