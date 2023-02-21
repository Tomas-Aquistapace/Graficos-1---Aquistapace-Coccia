#include "Sprite.h"
#include <iostream>

namespace Engine
{
	Sprite::Sprite(Renderer* renderer) : Entity(renderer)
	{
		_textureImporter = new TextureImporter();
	}

	Sprite::Sprite(Renderer* renderer, const ivec2& tileDimensions) : Entity(renderer)
	{
		_textureImporter = new TextureImporter();

		_animation = new Animation(tileDimensions);
	}

	Sprite::~Sprite()
	{
		_renderer->DeleteBuffers(_vao, _vbo, _ebo);

		if (_animation != NULL)
			delete _animation;
		if (_textureImporter != NULL)
			delete _textureImporter;
	}

	void Sprite::InitTexture()
	{
		_vertexSize = sizeof(_vertex);

		_renderer->SetVertexBuffer(_vertexSize, _vertex, _vao, _vbo);
		_renderer->SetIndexBuffer(_vertexSize, _index, _ebo);

		_renderer->SetVertexAttribPointer(false, _modelUniform);
	}
	
	void Sprite::ImportTexture(const char* name)
	{
		_textureImporter->ImportTexture(_renderer, name, _texture);
	}

	void Sprite::Draw()
	{
		_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

		_renderer->BindTexture(_texture);

		_renderer->Draw(_vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(_index) / sizeof(float));

		_renderer->DisableTexture();
	}

	void Sprite::DrawAnimation(vec4 uvRect)
	{
		if (_animation != NULL)
		{
			_animation->DrawAnimation(uvRect);

			_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

			_renderer->BindTexture(_texture);

			_renderer->Draw(_vao, _vbo, _ebo, _animation->GetVertex(), _vertexSize, sizeof(_index) / sizeof(float));

			_renderer->DisableTexture();
		}
		else
		{
			cout << "Add an animation in the constructor to use one" << endl;
		}
	}

	// --------------------------------
	
	vec4 Sprite::GetUVs(int index)
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
	
	void Sprite::SetColor(ENTITY_COLOR color) { }

	void Sprite::SetColor(float r, float g, float b) { }

	void Sprite::TriggerCollision(Entity* other) { }

	//void Sprite::SetAnimation()
	//{
	//	_animation = new Animation(); // para el final te agregamos una lista de animaciones
	//}

	Animation* Sprite::GetAnimation()
	{
		if (_animation != NULL)
		{
			return _animation;
		}
		else
		{
			cout << "Add an animation in the constructor to use one" << endl;
			return NULL;
		}
	}
}