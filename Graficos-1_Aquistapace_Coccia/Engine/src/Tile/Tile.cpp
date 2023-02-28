#include "Tile.h"

namespace Engine
{
	Tile::Tile(Renderer* renderer, const ivec2& tileDimensions, int index) : Entity(renderer)
	{
		_tileFrame = index;
		_dimensions = tileDimensions;

		_textureImporter = new TextureImporter();
	}

	Tile::~Tile()
	{
		if (_textureImporter != NULL)
			delete _textureImporter;
	}

	// --------------------------------

	void Tile::InitTexture()
	{
		_vertexSize = sizeof(_vertex);

		_renderer->SetVertexBuffer(_vertexSize, _vertex, _vao, _vbo);
		_renderer->SetIndexBuffer(_vertexSize, _index, _ebo);

		_renderer->SetVertexAttribPointer(false, _modelUniform);
	}

	void Tile::ImportTexture(const char* name)
	{
		InitTexture();

		_textureImporter->ImportTexture(_renderer, name, _texture);
	}

	void Tile::DrawTile()
	{
		vec4 uvRect = GetUVs(_tileFrame);

		//UpdateUVs
		_vertex[7] = _uv[0].x; _vertex[8] = _uv[0].y;
		_vertex[16] = _uv[1].x; _vertex[17] = _uv[1].y;
		_vertex[25] = _uv[2].x; _vertex[26] = _uv[2].y;
		_vertex[34] = _uv[3].x; _vertex[35] = _uv[3].y;

		//Set UV
		_uv[0].x = uvRect.x + uvRect.z; _uv[0].y = uvRect.y + uvRect.w;
		_uv[1].x = uvRect.x + uvRect.z; _uv[1].y = uvRect.y;
		_uv[2].x = uvRect.x; _uv[2].y = uvRect.y;
		_uv[3].x = uvRect.x; _uv[3].y = uvRect.y + uvRect.w;

		_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

		_renderer->BindTexture(_texture);

		_renderer->Draw(_vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(_index) / sizeof(float));

		_renderer->DisableTexture();
	}

	// ----------------------------------

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

	// --------------------------------

	void Tile::SetColor(ENTITY_COLOR color) { }
	void Tile::SetColor(float r, float g, float b) { }
	void Tile::TriggerCollision(Entity* other) { }
}