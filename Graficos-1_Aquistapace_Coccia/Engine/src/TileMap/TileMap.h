#ifndef TILEMAP_H
#define TILEMAP_H

#include "..\Tile\Tile.h"
#include "..\Export\Export.h"
#include "..\Shape\Shape.h"
#include "..\CollisionManager\CollisionManager.h"
#include <vector>

using namespace std;

namespace Engine
{
	class EXPORT_API TileMap : public Entity
	{
		//Texture* textureUsed;
		CollisionManager collMan;

		unsigned int texture;
		
		vector<Tile*> tiles;
		vector<Tile*> tilesLayout;
		
		unsigned int tilemapRows;
		unsigned int tilemapColumns;
		
		float _tileWidth;
		float _tileHeight;
		
		int _imageHeight;
		int _imageWidth;

		bool correctlySet;
		bool collidesWithTileMap(Shape* shape);

	public:
		TileMap(Renderer* renderer, int rows, int columns, const char* path, int imageHeight, int imageWidth, float tileWidth, float tileHeight);
		~TileMap();
		
		float tilemapWidth;
		float tilemapHeight;

		void setTileMap(int column, int row, vector<int> tilesId);
		void setTileMap(int column, int row, vector<vec2> tilesCoor);
		void setTileMap(int column, int row, vector<int> tilesId, vector<bool> tilesWalkable);
		void setTileMap(int column, int row, vector<vec2> tilesCoor, vector<bool> tilesWalkable);
		void drawTileMap();
		bool checkCollisionWithTileMap(Shape* sprite, vec3 movement);
	};
}
#endif