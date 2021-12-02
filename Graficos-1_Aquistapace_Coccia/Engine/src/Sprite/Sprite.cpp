#include "Sprite.h"

#include "GL\glew.h"
#include "glm\glm.hpp"

#include <iostream>

using namespace std;

namespace Engine
{	
	Sprite::Sprite(Renderer* renderer) : Entity(renderer)
	{
		_textureImporter = new TextureImporter();

		_animation = new Animation();
	}

	Sprite::Sprite(Renderer* renderer, const glm::ivec2& tileDimensions) : Entity(renderer)
	{
		_textureImporter = new TextureImporter();

		_animation = new Animation();
		_animation->InitSpriteSheet(this, tileDimensions);
	}

	Sprite::~Sprite()
	{
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ebo);

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

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);

		_renderer->Draw(_vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(_index) / sizeof(float));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisable(GL_TEXTURE_2D);
	}

	void Sprite::DrawAnimation(glm::vec4 uvRect)
	{
		//UpdateUVs
		_vertex[7] =  _uv[0].u; _vertex[8]  = _uv[0].v;
		_vertex[16] = _uv[1].u; _vertex[17] = _uv[1].v;
		_vertex[25] = _uv[2].u; _vertex[26] = _uv[2].v;
		_vertex[34] = _uv[3].u; _vertex[35] = _uv[3].v;

		//Set UV
		_uv[0].u = uvRect.x + uvRect.z; _uv[0].v = uvRect.y + uvRect.w;
		_uv[1].u = uvRect.x + uvRect.z; _uv[1].v = uvRect.y;
		_uv[2].u = uvRect.x; _uv[2].v = uvRect.y;
		_uv[3].u = uvRect.x; _uv[3].v = uvRect.y + uvRect.w;

		_renderer->UpdateModel(_generalMatrix.model, _modelUniform);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _texture);

		_renderer->Draw(_vao, _vbo, _ebo, _vertex, _vertexSize, sizeof(_index) / sizeof(float));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisable(GL_TEXTURE_2D);
	}
	// --------------------------------
	void Sprite::SetColor(ENTITY_COLOR color) { }

	void Sprite::SetColor(float r, float g, float b) { }

	void Sprite::TriggerCollision(Entity* other) { }

	void Sprite::SetAnimation()
	{
		_animation = new Animation(); // para el final te agregamos una lista de animaciones
	}

	Animation* Sprite::GetAnimation()
	{
		return _animation;
	}
}