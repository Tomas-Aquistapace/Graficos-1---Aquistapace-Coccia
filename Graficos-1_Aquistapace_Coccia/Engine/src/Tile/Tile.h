#ifndef TILE_H
#define TILE_H

#include "..\Export\Export.h"
#include "..\Sprite\Sprite.h"

namespace Engine
{
	class EXPORT_API Tile : public Sprite
	{
	private:
		//float _vertexes[32]
		//{
		//	// positions          // colors					// texture coords
		//	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		//	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
		//};

		UVs _uv[4];
		int _index;

		vec4 GetUVs(int index);

	public:
		Tile(Renderer* renderer);
		Tile(Renderer* renderer, const ivec2& tileDimensions);
		Tile(Renderer* renderer, const ivec2& tileDimensions, int index);
		~Tile();
		
		void DrawTile();

		Tile* clone();
	};
}
#endif