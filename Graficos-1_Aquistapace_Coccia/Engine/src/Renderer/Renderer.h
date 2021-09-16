#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "..\Export\Export.h"
#include "..\Shader\Shader.h"

namespace Engine
{
	class EXPORT_API Renderer
	{
	private:
		Shader* _shader;

	public:
		Renderer();
		~Renderer();
		
		int InitGlew();
		void CreateBuffer(int vertexCant, float* testvb, unsigned int& vbo, unsigned int& vao);
		void CreateShader();
		void DrawRenderer(unsigned int& vao);
		void StopShader();
	};
}
#endif