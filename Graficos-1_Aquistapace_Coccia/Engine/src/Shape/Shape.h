#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "..\Export\Export.h"
#include "..\Entity\Entity.h"

namespace Engine
{
	enum class TypeOfShape {
		Triangle,
		Quad
	};

	class EXPORT_API Shape : Entity
	{
	private:
		float vertex[18] = {
			/*Pos*/ -0.5f,  0.0f, 0.0f, /*Color*/ 1.0f, 1.0f, 1.0f,
			/*Pos*/  0.0f,  0.5f, 0.0f, /*Color*/ 1.0f, 1.0f, 1.0f,
			/*Pos*/  0.5f,  0.0f, 0.0f, /*Color*/ 1.0f, 1.0f, 1.0f
		};
		unsigned int vao; // Vertex Array Obj
		unsigned int vbo; // Vertex Buffer Obj

		// --------> HAY QUE METER EL "EBO" BUFFER

	public:
		Shape(TypeOfShape type);
		~Shape();

		void BindBuffers();

	};
}

#endif

