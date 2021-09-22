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

	void Renderer::CreateBuffer(TypeOfShape shape, int vertexCant, unsigned int& vao, unsigned int& vbo, unsigned int& ebo, float* testvb, unsigned int indexPos)
	{
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glBufferData(GL_ARRAY_BUFFER, vertexCant, testvb, GL_STATIC_DRAW);

		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexCant, testvb, GL_STATIC_DRAW);

		switch (shape)
		{
		case Engine::Triangle:
			// Para las posiciones
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
			glEnableVertexAttribArray(0);

			// Para los colores
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);
			break;
		case Engine::Quad:
			// Para las posiciones
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  sizeof(float) * 6, (void*)0);
			glEnableVertexAttribArray(0);

			// Para los colores
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);
			break;
		default:
			break;
		}
	}

	void Renderer::CreateShader()
	{
		_shader->SetShader();
		glUseProgram(_shader->GetShader());
	}

	void Renderer::DrawRenderer(TypeOfShape shape, int vertexCant, unsigned int &vao, unsigned int &vbo, unsigned int &ebo, float* testvb, float tamVertexs, unsigned int indexPos)
	{

		//std::cout << TypeOfShape::Triangle << std::endl;
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(_shader->GetShader());

		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ARRAY_BUFFER, tamVertexs, testvb, GL_STATIC_DRAW);
		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPos), (void*)indexPos, GL_STATIC_DRAW);


		if (shape == TypeOfShape::Triangle)
		{
			glDrawArrays(GL_TRIANGLES, 0, vertexCant);
		}
		else
		{
			glDrawElements(GL_TRIANGLES, vertexCant, GL_UNSIGNED_INT, 0);
		}

		//glBindVertexArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


		/*glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ARRAY_BUFFER, vertexCant, testvb, GL_STATIC_DRAW);
		
			
		if (shape == TypeOfShape::Triangle)
		{
			glDrawArrays(GL_TRIANGLES, 0, tamVertexs);
		}
		else
		{
			glDrawElements(GL_TRIANGLES, tamVertexs, GL_UNSIGNED_INT, 0);
		}
		
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/
		//glUseProgram(0);

		//glClear(GL_COLOR_BUFFER_BIT);
		//
		////glUseProgram(_shader->GetShader()); //por que esto esta aca??? Que hace???
		//glBindVertexArray(vao);
		//
		//glDrawArrays(GL_TRIANGLES, 0, 3); // ------> USAR DRAW ELEMENTS
	}

	void Renderer::StopShader()
	{
		if (_shader != NULL)
		{
			_shader->ClearShader();
		}
	}
}