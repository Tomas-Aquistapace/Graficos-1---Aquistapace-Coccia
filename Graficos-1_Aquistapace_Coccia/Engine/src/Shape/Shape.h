#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "..\Export\Export.h"
#include "..\Entity\Entity.h"

namespace Engine
{
	class EXPORT_API Shape : public Entity
	{
	private:
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

		unsigned int indexTris[3] = {
			0,1,2,
		};

		unsigned int indexPos[6] = {
			0,1,2,
			3,2,0
		};

		int _vertexSize;
		float* _vertex;

		unsigned int _vao; // Vertex Array Obj
		unsigned int _vbo; // Vertex Buffer Obj
		unsigned int _ebo; // Index Buffer Obj
		
		TypeOfShape _shape;
		unsigned int _modelUniform;

	public:
		Shape(Renderer* renderer);
		~Shape();
		void InitShape(TypeOfShape type);
		void Draw();
	};
}

#endif

