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

	void Sprite::DrawFrame(int index)
	{
		if (_animation != NULL)
		{
			vec4 uvRect = _animation->GetUVs(index);

			_animation->DrawAnimation(uvRect);

			_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

			_renderer->BindTexture(_texture);

			_renderer->Draw(_vao, _vbo, _ebo, _animation->GetVertex(), _vertexSize, sizeof(_index) / sizeof(float));

			_renderer->DisableTexture();
		}
		else
		{
			cout << "Error - Sprite.cpp - DrawFrame: Add an animation in the constructor to use one" << endl;
		}
	}

	void Sprite::DrawAnimation()
	{
		if (_animation != NULL)
		{
			vec4 uvRect = _animation->GetUVsFromVector(_animation->GetCurrentFrame());

			_animation->DrawAnimation(uvRect);

			_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

			_renderer->BindTexture(_texture);

			_renderer->Draw(_vao, _vbo, _ebo, _animation->GetVertex(), _vertexSize, sizeof(_index) / sizeof(float));

			_renderer->DisableTexture();
		}
		else
		{
			cout << "Error - Sprite.cpp - DrawAnimation(): Add an animation in the constructor to use one" << endl;
		}
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
			cout << "Error - Sprite.cpp - GetAnimation(): Add an animation in the constructor to use one" << endl;
			return NULL;
		}
	}
}