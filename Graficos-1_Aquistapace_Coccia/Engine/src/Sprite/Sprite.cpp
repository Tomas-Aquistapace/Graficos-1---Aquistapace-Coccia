#include "Sprite.h"

#include "GL/glew.h"
#include "..\TextureImporter\stb_image.h"

#include <iostream>

using namespace std;

namespace Engine
{
	unsigned int _vao;
	unsigned int _vbo;
	unsigned int _ebo;

	float triangleTextCoords[] 
	{
		0.0f, 0.0f, // lower-left corner 
		1.0f, 0.0f, // lower-right corner 
		0.5f, 1.0f  // top-center corner 
	};
	
	float vertex[]
	{
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
	};

	float borderColor[]
	{
		1.0f, 1.0f, 0.0f, 1.0f
	};

	unsigned int index[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	Sprite::Sprite(Renderer* renderer) : Entity(renderer)
	{

	}
	Sprite::~Sprite()
	{

	}
	void Sprite::BindTexture()
	{
		glGenVertexArrays(1, &_vao);
		glGenBuffers(1, &_vbo);
		glGenBuffers(1, &_ebo);

		glBindVertexArray(_vao);

		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void Sprite::SetTexParameter()
	{
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		
		//ACA HAY UN ERROR
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	
	void Sprite::ImportTexture(const char* name)
	{
		data = stbi_load(name, &width, &height, &nrChannels, 0);
		
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			cout << "failed to load texture" << endl;
		}
		stbi_image_free(data);
	}

	void Sprite::Draw()
	{
		_renderer->GetShader();
		glBindVertexArray(_vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	void Sprite::SetColor(ENTITY_COLOR color)
	{

	}
	void Sprite::SetColor(float r, float g, float b)
	{

	}
}