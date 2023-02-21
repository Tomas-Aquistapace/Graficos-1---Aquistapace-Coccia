#ifndef TILE_H
#define TILE_H

#include "..\Export\Export.h"
#include "..\Sprite\Sprite.h"

namespace Engine
{
	class EXPORT_API Tile : public Sprite
	{
		int _id;
		bool _isWalkable;

		float _vertexes[32]
		{
			// positions          // colors					// texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
		};

	public:
		Tile(Renderer* renderer, int id);
		Tile(Renderer* renderer, const ivec2& tileDimensions, int id);
		~Tile();
		
		Tile* clone();

		void setWalkable(bool isWalkable);
	};
}
#endif