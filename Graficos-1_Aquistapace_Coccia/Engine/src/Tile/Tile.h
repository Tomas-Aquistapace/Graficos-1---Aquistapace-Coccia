#ifndef TILE_H
#define TILE_H

#include "..\Export\Export.h"
#include "..\Sprite\Sprite.h"

namespace Engine
{
	class EXPORT_API Tile : public Sprite
	{
	private:

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