#include "Shape.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	float triangleVertex[18] = {
		/*Pos*/ -0.5f,  0.0f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/  0.0f,  0.5f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f,
		/*Pos*/  0.5f,  0.0f, 0.0f, /*Color*/ 1.0f, 0.0f, 0.0f
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
		switch (type)
		{
		case Engine::TypeOfShape::Triangle:

			_vertex = triangleVertex;
			_vertexSize = sizeof(triangleVertex);
		
			break;
		case Engine::TypeOfShape::Quad:

			break;
		}

		_renderer->CreateBuffer(_vertexSize, _vertex, _vbo, _vao);

	}

	void Shape::Draw()
	{
		_renderer->DrawRenderer(_vao);
	}
}