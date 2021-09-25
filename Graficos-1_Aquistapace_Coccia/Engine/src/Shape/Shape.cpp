#include "Shape.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	float triangleVertex[18] = {
		/*Pos*/ -0.1f,  0.0f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/  0.0f,  0.2f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/  0.1f,  0.0f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f
	};

	float quadVertex[24] = {
		/*Pos*/-0.1f,  0.1f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/-0.1f, -0.1f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/ 0.1f, -0.1f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/ 0.1f,  0.1f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f
	};
	unsigned int indexPos[] = {
		0,1,2,
		3,2,0
	};
	// =======================================================
	Shape::Shape(Renderer* renderer) : Entity(renderer)
	{
		
	}

	Shape::~Shape()
	{
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
	}

	void Shape::InitShape(TypeOfShape type)
	{
		_shape = type;
		
		switch (type)
		{
		case TypeOfShape::Triangle:

			_vertex = triangleVertex;
			_vertexSize = sizeof(triangleVertex);

			_renderer->SetVertexBuffer(_vertexSize, _vertex, _vao, _vbo);
			
			/*glGenVertexArrays(1, &_vao);
			glGenBuffers(1, &_vbo);
			glGenBuffers(1, &_ebo);
			
			glBindVertexArray(_vao);
			
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(_vertex), _vertex, GL_STATIC_DRAW);
			
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPos), indexPos, GL_STATIC_DRAW);
			
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
			glEnableVertexAttribArray(0);

			//Para los colores
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);*/
			break;
		case TypeOfShape::Quad:
			_vertex = quadVertex;
			_vertexSize = sizeof(quadVertex);

			_renderer->SetVertexBuffer(_vertexSize, _vertex, _vao, _vbo);
			_renderer->SetIndexBuffer(_vertexSize, indexPos, _ebo);
			
			/*glGenVertexArrays(1, &_vao);
			glGenBuffers(1, &_vbo);
			glGenBuffers(1, &_ebo);
			
			glBindVertexArray(_vao);
			
			glBindBuffer(GL_ARRAY_BUFFER, _vbo);
			glBufferData(GL_ARRAY_BUFFER, _vertexSize, _vertex, GL_STATIC_DRAW);
			
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPos), indexPos, GL_STATIC_DRAW);
			
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
			glEnableVertexAttribArray(0);
			
			// Para los colores
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);*/
			break;
		}
		if (_shape == TypeOfShape::Triangle)
		{
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(0));
			glEnableVertexAttribArray(0);
		}
		else
		{
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
			glEnableVertexAttribArray(0);
		}
	}

	void Shape::Draw()
	{
		_renderer->Draw(_shape, _vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(indexPos) / sizeof(float));
		
		/*glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, _vertexSize, _vertex, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexPos), indexPos, GL_STATIC_DRAW);
		
		glUseProgram(0);
		glBindVertexArray(_vao);
		if (_shape == TypeOfShape::Triangle)
		{
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}
		else
		{
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/
	}
}