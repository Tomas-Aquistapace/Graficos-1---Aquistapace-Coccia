#include "Renderer.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm\gtc\type_ptr.hpp"

namespace Engine
{
	Renderer::Renderer()
	{		
		_shader = new Shader();
		_camera = new Camera();
	}

	Renderer::~Renderer()
	{
		if (_shader != NULL)
		{
			delete _shader;
			_shader = NULL;
		}
		
		if (_camera != NULL)
		{
			delete _camera;
			_camera = NULL;
		}
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
		_shader->SetShader("../Engine/shaders/Vertex.shader", "../Engine/shaders/Fragment.shader");
		glUseProgram(_shader->GetShader());
	}
	
	void Renderer::Draw(TypeOfShape shape, unsigned int& vao, unsigned int& vbo, unsigned int& ebo, float* vertex, float vertexSize, int vertexCount)
	{
		glUseProgram(_shader->GetShader());
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);


		unsigned int colorLocation = glGetAttribLocation(GetShader(), "color");
		glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(colorLocation);


		glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glUseProgram(0);
	}

	void Renderer::UpdateModel(glm::mat4 model, unsigned int modelUniform)
	{
		glUseProgram(_shader->GetShader());
		glUniformMatrix4fv(modelUniform, 1, GL_FALSE, glm::value_ptr(model));

		_camera->UpdateMVP(model, _shader->GetShader());

		glUseProgram(0);
	}
	
	void Renderer::StopShader()
	{
		if (_shader != NULL)
		{
			_shader->ClearShader();
		}
	}

	// ----------------------------

	unsigned int Renderer::GetShader() 
	{
		return _shader->GetShader();
	}
}