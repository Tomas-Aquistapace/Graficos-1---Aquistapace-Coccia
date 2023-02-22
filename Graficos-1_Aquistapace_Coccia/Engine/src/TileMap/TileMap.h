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
	class EXPORT_API TileMap : public Entity
	{
	private:
		vector<Tile*> _tilesVector;

	public:
		TileMap(Renderer* renderer);
		~TileMap();

		void InitTileMap(vec3 startPosition, const char* path, const ivec2& tileDimensions, vector<vector<TileModule>> tileModule, vec2 tileScale);
		
		void DrawTileMap();

		// ----------------------
		
		void SetColor(ENTITY_COLOR color);
		void SetColor(float r, float g, float b);
		void TriggerCollision(Entity* other);
	};
}
#endif