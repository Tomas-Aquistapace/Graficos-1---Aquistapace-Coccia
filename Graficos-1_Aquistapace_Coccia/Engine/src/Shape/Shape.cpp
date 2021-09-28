#include "Shape.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{
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
			_renderer->SetIndexBuffer(_vertexSize, indexTris, _ebo);
			
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(0));
			glEnableVertexAttribArray(0);
			break;

		case TypeOfShape::Quad:
			_vertex = quadVertex;
			_vertexSize = sizeof(quadVertex);

			_renderer->SetVertexBuffer(_vertexSize, _vertex, _vao, _vbo);
			_renderer->SetIndexBuffer(_vertexSize, indexPos, _ebo);
			
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
			glEnableVertexAttribArray(0);
			break;
		}

		_modelUniform = glGetUniformLocation(_renderer->GetShader(), "model");
	}

	void Shape::Draw()
	{
		_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

		switch (_shape)
		{
		case TypeOfShape::Triangle:
			_renderer->Draw(_shape, _vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(indexTris) / sizeof(float));
			break;

		case TypeOfShape::Quad:
			_renderer->Draw(_shape, _vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(indexPos) / sizeof(float));
			break;
		}
	}
}