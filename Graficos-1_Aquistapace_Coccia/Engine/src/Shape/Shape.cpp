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
			break;

		case TypeOfShape::Quad:
			_vertex = quadVertex;
			_vertexSize = sizeof(quadVertex);

			_renderer->SetVertexBuffer(_vertexSize, _vertex, _vao, _vbo);
			_renderer->SetIndexBuffer(_vertexSize, indexPos, _ebo);
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
		//triangleVertex[0] += 0.001f;
        //triangleVertex[6] += 0.001f;
        //triangleVertex[12] += 0.001f;
        //_vertex = triangleVertex;
		
		_renderer->Draw(_shape, _vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(indexPos) / sizeof(float));
	}
}