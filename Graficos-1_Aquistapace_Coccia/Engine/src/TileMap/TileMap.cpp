#include "TileMap.h"
#include <iostream>

namespace Engine
{
	TileMap::TileMap(Renderer* renderer)
	{
		_renderer = renderer;

		_tilesVector.clear();
	}

	TileMap::~TileMap()
	{
		for (Tile* item : _tilesVector)
		{
			if (item != NULL)
			{
				delete item;
			}
		}
	}

	void TileMap::InitTileMap(vec3 startPosition, const char* path, const ivec2& tileDimensions, vector<vector<TileModule>> tileModule, vec2 tileScale)
	{
		vec3 pos = startPosition;

		int rows = tileModule.size();
		int columns = tileModule[0].size();

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				Tile* tile = new Tile(_renderer, tileDimensions, tileModule[i][j]._tileFrame);

				tile->InitTexture();
				tile->ImportTexture(path);

				tile->SetScale(tileScale.x, tileScale.y, 0);
				tile->SetPosition(pos.x, pos.y, pos.z);

				_tilesVector.push_back(tile);
				
				pos = vec3(pos.x + (tileScale.x), pos.y, pos.z);
			}

			pos = vec3(startPosition.x, pos.y + (tileScale.y), pos.z);
		}
	}

	void TileMap::DrawTileMap() 
	{
		for(Tile* item : _tilesVector)
		{
			item->DrawTile();
		}
	}
}