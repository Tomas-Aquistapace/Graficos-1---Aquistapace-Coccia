#ifndef TILE_H
#define TILE_H

#include "..\Entity\Entity.h"
#include "..\TextureImporter\TextureImporter.h"

#include "glm/glm/glm.hpp"
#include <vector>

using namespace glm;
using namespace std;

namespace Engine
{
	class EXPORT_API Tile : public Entity
	{
	private:
		float _vertex[36]
		{
			// positions          // colors					// texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left
		};

		unsigned int _index[6] =
		{
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
		};

		unsigned int _vao; // Vertex Array Obj
		unsigned int _vbo; // Vertex Buffer Obj
		unsigned int _ebo; // Index Buffer Obj

		int _vertexSize;
		unsigned int _texture;
		unsigned int _modelUniform;

		vec4 uvs = vec4(0, 0, 0, 0);
		ivec2 _dimensions;

		vec2 _uv[4]; // x = u , y = v
		int _tileFrame;

		TextureImporter* _textureImporter;

		void InitTexture();	
		vec4 GetUVs(int index);

	public:
		Tile(Renderer* renderer, const ivec2& tileDimensions, int index);
		~Tile();

		void ImportTexture(const char* name);

		void DrawTile();

		void SetColor(ENTITY_COLOR color);
		void SetColor(float r, float g, float b);
		void TriggerCollision(Entity* other);
	};
}
#endif