#include "Sprite.h"
#include <iostream>

namespace Engine
{
	Sprite::Sprite(Renderer* renderer) : Entity(renderer)
	{
		_textureImporter = new TextureImporter();
	}

	Sprite::~Sprite()
	{
		_renderer->DeleteBuffers(_vao, _vbo, _ebo);

		if (_textureImporter != NULL)
			delete _textureImporter;

		for (Animation* item : _animations)
		{
			if (item != NULL)
				delete item;
		}
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
		InitTexture();

		_textureImporter->ImportTexture(_renderer, name, _texture);
	}

	// -------------------------------
	
	void Sprite::AddAnimation(string id, const ivec2& tileDimensions, float durationInSec, int firstIndex, int lastIndex)
	{
		_animations.push_back(new Animation(id, tileDimensions));
		_animations.back()->SetFrame(durationInSec, firstIndex, lastIndex);
	}

	// -------------------------------

	void Sprite::Draw()
	{
		_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

		_renderer->BindTexture(_texture);

		_renderer->Draw(_vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(_index) / sizeof(float));

		_renderer->DisableTexture();
	}

	void Sprite::DrawFrame(string id, int index)
	{
		for (int i = 0; i < _animations.size(); i++)
		{
			if (_animations[i] != NULL)
			{
				if (_animations[i]->GetId() == id)
				{
					_animations[i]->DrawAnimation(index);

					_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

					_renderer->BindTexture(_texture);

					_renderer->Draw(_vao, _vbo, _ebo, _animations.front()->GetVertex(), _vertexSize, sizeof(_index) / sizeof(float));

					_renderer->DisableTexture();
				}
			}
		}
		
		cout << "Error - Sprite.cpp - DrawFrame: Add an animation in the constructor to use one" << endl;
	}

	void Sprite::DrawAnimation(string id, float deltaTime)
	{
		for (int i = 0; i < _animations.size(); i++)
		{
			if (_animations[i] != NULL)
			{
				if (_animations[i]->GetId() == id)
				{
					_animations[i]->DrawAnimation(deltaTime);

					_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

					_renderer->BindTexture(_texture);

					_renderer->Draw(_vao, _vbo, _ebo, _animations[i]->GetVertex(), _vertexSize, sizeof(_index) / sizeof(float));

					_renderer->DisableTexture();

					return;
				}
			}
		}

		cout << "Error - Sprite.cpp - DrawAnimation(): animation /" << id << "/ not found" << endl;
	}
	
	void Sprite::DrawAnimation(int id, float deltaTime)
	{
		for (size_t i = 0; i < _animations.size(); i++)
		{
			if (_animations[i] != NULL)
			{
				if (i == id)
				{
					_animations[i]->DrawAnimation(deltaTime);

					_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

					_renderer->BindTexture(_texture);

					_renderer->Draw(_vao, _vbo, _ebo, _animations[i]->GetVertex(), _vertexSize, sizeof(_index) / sizeof(float));

					_renderer->DisableTexture();

					return;
				}
			}
		}

		cout << "Error - Sprite.cpp - DrawAnimation(): animation /" << id << "/ not found" << endl;
	}

	// --------------------------------
	
	Animation* Sprite::GetAnimation(string id)
	{
		for (size_t i = 0; i < _animations.size(); i++)
		{
			if (_animations[i] != NULL)
			{
				if (_animations[i]->GetId() == id)
				{
					return _animations[i];
				}
			}
		}
		
		cout << "Error - Sprite.cpp - DrawAnimation(): animation /" << id << "/ not found" << endl;
		return NULL;
	}

	Animation* Sprite::GetAnimation(int id)
	{
		for (size_t i = 0; i < _animations.size(); i++)
		{
			if (_animations[i] != NULL)
			{
				if (i == id)
				{
					return _animations[i];
				}
			}
		}

		cout << "Error - Sprite.cpp - DrawAnimation(): animation /" << id << "/ not found" << endl;
		return NULL;
	}
	
	// ---------------------------------

	void Sprite::SetColor(ENTITY_COLOR color) { }

	void Sprite::SetColor(float r, float g, float b) { }

	void Sprite::TriggerCollision(Entity* other) { }
}