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
		int vertexSize;
		float* vertex;
		unsigned int vao; // Vertex Array Obj
		unsigned int vbo; // Vertex Buffer Obj

		// --------> HAY QUE METER EL "EBO" BUFFER

	public:
		Shape(/*TypeOfShape type*/);
		~Shape();

		void BindBuffers();
		void Draw();
	};
}

#endif

