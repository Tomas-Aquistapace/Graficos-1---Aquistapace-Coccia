#include "Tile.h"

namespace Engine
{
	Tile::Tile(Renderer* renderer) : Sprite(renderer)
	{
		_index = 0;
		_dimensions = ivec2(0,0);
	}

	Tile::Tile(Renderer* renderer, const ivec2& tileDimensions) : Sprite(renderer, tileDimensions)
	{
		_index = 0;
		_dimensions = tileDimensions;
	}

	Tile::Tile(Renderer* renderer, const ivec2& tileDimensions, int index) : Sprite(renderer)
	{
		_index = index;
		_dimensions = tileDimensions;
	}

	Tile::~Tile()
	{

	}

	Tile* Tile::clone()
	{
		//Tile* clonedTile = new Tile(_renderer, GetAnimation()->GetDimensions(), _id);
		//
		//unsigned int uStart = 3;
		//unsigned int vStart = 4;
		//unsigned int stride = _renderer->GetAttribElementsAmount();
		//unsigned int vertexNum = 0;
		//
		//float texCoordinates[8];
		//
		//for (int i = 0; i < 8; i++)
		//{
		//	if (i % 2 == 0)
		//		texCoordinates[i] = _vertexes[stride * vertexNum + uStart];
		//	else
		//	{
		//		texCoordinates[i] = _vertexes[stride * vertexNum + vStart];
		//		vertexNum++;
		//	}
		//}

		//clonedTile->setTextureCoordinates(texCoordinates[0], texCoordinates[1], texCoordinates[2], texCoordinates[3], texCoordinates[4], texCoordinates[5], texCoordinates[6], texCoordinates[7]);

		//return clonedTile;
		return NULL;
	}

	// --------------------------------

	void Tile::DrawTile()
	{
		vec4 uvRect = GetUVs(_index);

		//UpdateUVs
		_vertex[7] = _uv[0].u; _vertex[8] = _uv[0].v;
		_vertex[16] = _uv[1].u; _vertex[17] = _uv[1].v;
		_vertex[25] = _uv[2].u; _vertex[26] = _uv[2].v;
		_vertex[34] = _uv[3].u; _vertex[35] = _uv[3].v;

		//Set UV
		_uv[0].u = uvRect.x + uvRect.z; _uv[0].v = uvRect.y + uvRect.w;
		_uv[1].u = uvRect.x + uvRect.z; _uv[1].v = uvRect.y;
		_uv[2].u = uvRect.x; _uv[2].v = uvRect.y;
		_uv[3].u = uvRect.x; _uv[3].v = uvRect.y + uvRect.w;

		Draw();
	}

	vec4 Tile::GetUVs(int index)
	{
		int xTile = index % _dimensions.x; //Esto impide que xTile sea mayor a la dimension en x
		int yTile = index / _dimensions.x;

		uvs.x = xTile / (float)_dimensions.x; //posicion en x
		uvs.y = yTile / (float)_dimensions.y; //posicion en y
		uvs.z = 1.0f / (float)_dimensions.x;  //ancho
		uvs.w = 1.0f / (float)_dimensions.y;  //alto

		return uvs;
	}
}