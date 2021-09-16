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

	TypeOfShape actualType;

	Shape::Shape(/*TypeOfShape type*/)
	{
		//actualType = type;
		vertex = triangleVertex;
		vertexSize = sizeof(triangleVertex);
		//switch (actualType)
		//{
		//case Engine::TypeOfShape::Triangle:
		//
		//	break;
		//case Engine::TypeOfShape::Quad:
		//	break;
		//default:
		//	break;
		//}
	}

	Shape::~Shape()
	{

	}

	void Shape::BindBuffers()
	{
		_renderer->CreateBuffer(vertexSize,vertex,vbo,vao);
		//glGenVertexArrays(1, &vao);
		//glGenBuffers(1, &vbo);
		//
		//glBindVertexArray(vao);
		//glBindBuffer(GL_ARRAY_BUFFER, vbo);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
		//
		//// Para las posiciones
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
		//glEnableVertexAttribArray(0);
		//
		//// Para los colores
		//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(3 * sizeof(float)));
		//glEnableVertexAttribArray(1);
	}
	void Shape::Draw()
	{
		_renderer->DrawRenderer(vao);
	}
}