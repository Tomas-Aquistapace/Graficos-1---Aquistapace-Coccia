#include "TileMap.h"
#include <iostream>

namespace Engine
{
	TileMap::TileMap(Renderer* renderer)
	{
		_renderer = renderer;

		_tileDimensions = ivec2(0,0);

		_startPosition = vec3(0,0,0);
		_tileScale = vec2(0,0);

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
		_tileDimensions = tileDimensions;
		_startPosition = startPosition;
		_tileScale = tileScale;

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

	void TileMap::CheckTileCollisions(Entity* object)
	{
		float convertedPosX = ((object->_transform.position.y - _startPosition.y) + (_tileScale.y / 2)) / _tileScale.y;
		float convertedPosY = ((object->_transform.position.x - _startPosition.x) + (_tileScale.x / 2)) / _tileScale.x;

		vec2 objectScale = vec2((object->_transform.scale.x / _tileScale.x) / 2, 
								(object->_transform.scale.y / _tileScale.y) / 2);

		cout << "Esta en el tile: " << (int)convertedPosX << ":" << (int)convertedPosY << endl;

		vector<ivec2> tiles =
		{
			vec2(convertedPosX + objectScale.x, convertedPosY + objectScale.y),
			vec2(convertedPosX - objectScale.x, convertedPosY + objectScale.y),
			vec2(convertedPosX + objectScale.x, convertedPosY - objectScale.y),
			vec2(convertedPosX - objectScale.x, convertedPosY - objectScale.y),
		};

		bool collision = false;

		for (int i = 0; i < tiles.size(); i++)
		{
			if (CollisionWithATile(object, tiles[i]))
			{
				object->TriggerCollision(_tilesVector[tiles[i].x][tiles[i].y]);
				break;
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

	// ---------------------

	bool TileMap::CollisionWithATile(Entity* object, ivec2 tile)
	{
		if (tile.x >= 0 && tile.y >= 0)
		{
			if (tile.x < _tilesVector.size() && tile.y < _tilesVector[0].size())
			{
				if (_tilesVector[tile.x][tile.y]->GetColliderState())
				{
					cout << "Colisiono con el tile: " << tile.x << ":" << tile.y << endl;
					return true;
				}
			}
		}

		return false;
	}
}