#include "Renderer.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	float vertex[18] = {
		/*Pos*/ -0.5f,  0.0f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/  0.0f,  0.5f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/  0.5f,  0.0f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f
	};
	unsigned int vao; // Vertex Array Obj 
	unsigned int vbo; // Vertex Buffer Obj

	// HAY QUE METER EL "EBO" BUFFER

	//====================================\\

	Renderer::Renderer()
	{		
		_shader = new Shader();
	}

	Renderer::~Renderer()
	{
		if (_shader != NULL)
			delete _shader;

		glDeleteProgram(_shader->GetShader());
	}

	int Renderer::InitGlew()
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Error in Glew Init" << std::endl;
			return -1;
		}
	}

	void Renderer::CreateBuffer()
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

		// Para las posiciones
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
		glEnableVertexAttribArray(0);
		
		// Para los colores
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	void Renderer::CreateShader()
	{
		_shader->SetShader();
		glUseProgram(_shader->GetShader());
	}

	void Renderer::DrawRenderer()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(_shader->GetShader());
		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}