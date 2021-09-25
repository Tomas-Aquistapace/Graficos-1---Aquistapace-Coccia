#include "Renderer.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	Renderer::Renderer()
	{		
		_shader = new Shader();
	}

	Renderer::~Renderer()
	{
		if (_shader != NULL)
			delete _shader;
	}

	int Renderer::InitGlew()
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Error in Glew Init" << std::endl;
			return -1;
		}
	}

	void Renderer::SetVertexBuffer(int size, float* vertex, unsigned int& vao, unsigned int& vbo)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glBufferData(GL_ARRAY_BUFFER, size, vertex, GL_STATIC_DRAW);
	}

	void Renderer::SetIndexBuffer(int size, unsigned int* index, unsigned int &ebo)
	{
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, index, GL_STATIC_DRAW);
	}
	
	void Renderer::SetAtrtribs(int size, int stride, int offset)
	{
		glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
	}

	void Renderer::CreateShader()
	{
		_shader->SetShader();
		glUseProgram(_shader->GetShader());
	}

	
	void Renderer::Draw(TypeOfShape shape, unsigned int& vao, unsigned int& vbo, unsigned int& ebo, float* vertex, float vertexSize, int vertexCount)
	{
		
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(_shader->GetShader()); // no estabamos usando esto correctamente por eso no tenia color 
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);

		if (shape == TypeOfShape::Triangle)
		 glDrawArrays(GL_TRIANGLES, 0, vertexCount);
		else
		 glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glUseProgram(0);
	}
	
	void Renderer::StopShader()
	{
		if (_shader != NULL)
		{
			_shader->ClearShader();
		}
	}
}