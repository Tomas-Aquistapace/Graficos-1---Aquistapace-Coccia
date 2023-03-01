#ifndef TILEMAP_H
#define TILEMAP_H

#include "..\Export\Export.h"
#include "..\Shape\Shape.h"
#include "..\Tile\Tile.h"
#include "..\Tile\TileModule.h"
#include "..\CollisionManager\CollisionManager.h"

#include <vector>

using namespace std;

namespace Engine
{
	class EXPORT_API TileMap
	{
	private:
		vector<vector<Tile*>> _tilesVector;

		Renderer* _renderer;
		CollisionManager* _collisionManager;

	public:
		TileMap(Renderer* renderer, CollisionManager* collisionManager);
		~TileMap();

		void InitTileMap(vec3 startPosition, const char* path, const ivec2& tileDimensions, vector<vector<TileModule>> tileModule, vec2 tileScale);
		
		void DrawTileMap();

		vector<vector<Tile*>> GetTilesVector();
		Tile* GetTile(int row, int column);
	};
}
#endif