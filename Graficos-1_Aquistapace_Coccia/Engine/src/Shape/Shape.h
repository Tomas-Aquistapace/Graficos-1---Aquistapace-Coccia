#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "..\Export\Export.h"
#include "..\Entity\Entity.h"

namespace Engine
{
	class EXPORT_API Shape : Entity
	{
	private:
		int _vertexSize;
		float* _vertex;
		unsigned int _vao; // Vertex Array Obj
		unsigned int _vbo; // Vertex Buffer Obj
		unsigned int _ebo; // Buffer Obj

		// --------> HAY QUE METER EL "EBO" BUFFER

	public:
		Shape(Renderer* renderer);
		~Shape();

		void InitShape(TypeOfShape type);
		void Draw();
	};
}

#endif

