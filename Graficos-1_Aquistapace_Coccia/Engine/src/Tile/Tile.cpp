#include "Tile.h"

namespace Engine
{
	Tile::Tile(Renderer* renderer, int id) : Sprite(renderer)
	{
		_id = id;
		_isWalkable = true;
	}

	Tile::Tile(Renderer* renderer, const ivec2& tileDimensions, int id) : Sprite(renderer, tileDimensions)
	{
		_id = id;
		_isWalkable = true;
	}

	Tile::~Tile()
	{

	}

	Tile* Tile::clone()
	{
		Tile* clonedTile = new Tile(_renderer, GetAnimation()->GetDimensions(), _id);

		unsigned int uStart = 3;
		unsigned int vStart = 4;
		unsigned int stride = _renderer->GetAttribElementsAmount();
		unsigned int vertexNum = 0;

		float texCoordinates[8];
		
		for (int i = 0; i < 8; i++)
		{
			if (i % 2 == 0)
				texCoordinates[i] = _vertexes[stride * vertexNum + uStart];
			else
			{
				texCoordinates[i] = _vertexes[stride * vertexNum + vStart];
				vertexNum++;
			}
		}

		//clonedTile->setTextureCoordinates(texCoordinates[0], texCoordinates[1], texCoordinates[2], texCoordinates[3], texCoordinates[4], texCoordinates[5], texCoordinates[6], texCoordinates[7]);

		return clonedTile;
	}

	void Tile::setWalkable(bool isWalkable)
	{
		_isWalkable = isWalkable;
	}
}