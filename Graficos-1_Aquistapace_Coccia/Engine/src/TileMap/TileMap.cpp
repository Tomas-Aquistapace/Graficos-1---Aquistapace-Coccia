#include "TileMap.h"
#include <iostream>

namespace Engine
{
	TileMap::TileMap(Renderer* renderer, CollisionManager* collisionManager)
	{
		_renderer = renderer;
		_collisionManager = collisionManager;

		_tilesVector.clear();
	}

	TileMap::~TileMap()
	{
		for (int i = 0; i < _tilesVector.size(); i++)
		{
			for (int j = 0; j < _tilesVector[0].size(); j++)
			{
				if (_tilesVector[i][j] != NULL)
				{
					delete _tilesVector[i][j];
				}
			}
		}
	}

	void TileMap::InitTileMap(vec3 startPosition, const char* path, const ivec2& tileDimensions, vector<vector<TileModule>> tileModule, vec2 tileScale)
	{
		vec3 pos = startPosition;

		int rows = tileModule.size();
		int columns = tileModule[0].size();

		_tilesVector.resize(rows);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				Tile* tile = new Tile(_renderer, tileDimensions, tileModule[i][j]._tileFrame);

				tile->ImportTexture(path);

				tile->SetScale(tileScale.x, tileScale.y, 1);
				tile->SetPosition(pos.x, pos.y, pos.z);
				tile->SetColliderState(tileModule[i][j]._collider);

				_tilesVector[i].push_back(tile);
				
				pos = vec3(pos.x + (tileScale.x), pos.y, pos.z);

				_collisionManager->AddNewObject(tile);
			}

			pos = vec3(startPosition.x, pos.y + (tileScale.y), pos.z);
		}
	}

	void TileMap::DrawTileMap() 
	{
		for (int i = 0; i < _tilesVector.size(); i++)
		{
			for (int j = 0; j < _tilesVector[0].size(); j++)
			{
				_tilesVector[i][j]->DrawTile();
			}
		}
	}

	vector<vector<Tile*>> TileMap::GetTilesVector()
	{
		return _tilesVector;
	}

	Tile* TileMap::GetTile(int row, int column)
	{
		return _tilesVector[row][column];
	}
}