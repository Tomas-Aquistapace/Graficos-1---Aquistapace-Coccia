#include "Sprite.h"

#include "GL/glew.h"
#include "..\TextureImporter\stb_image.h"

#include <iostream>

using namespace std;

namespace Engine
{	
	Sprite::Sprite(Renderer* renderer) : Entity(renderer)
	{

	}

	Sprite::~Sprite()
	{
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ebo);
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
		stbi_set_flip_vertically_on_load(true);

		data = stbi_load(name, &_width, &_height, &_nrChannels, 0);
		
		if (!data)
		{
			cout << "failed to load texture" << endl;
			return;
		}

		glGenTextures(1, &_texture);
		glBindTexture(GL_TEXTURE_2D, _texture);

		// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		if (_nrChannels == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}

		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(data);
		
		glUseProgram(_renderer->GetShader());
		glUniform1i(glGetUniformLocation(_renderer->GetShader(), "ourTexture"), 0);
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

	void Sprite::SetColor(ENTITY_COLOR color)
	{

	}

	void Sprite::SetColor(float r, float g, float b)
	{

	}

	void Sprite::TriggerCollision(Entity* other)
	{

	}
}