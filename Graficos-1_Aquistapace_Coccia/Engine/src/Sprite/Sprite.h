#ifndef SPRITE_H
#define SPRITE_H

#include "..\Export\Export.h"
#include "..\Entity\Entity.h"

namespace Engine
{
	class EXPORT_API Sprite : public Entity
	{
		float _vertex[36]
		{
			// positions          // colors					// texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left
		};

		float _borderColor[4]
		{
			1.0f, 1.0f, 0.0f, 1.0f
		};

		unsigned int _index[6] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
		};

		unsigned int _vao;
		unsigned int _vbo;
		unsigned int _ebo;

		int _width, _height, _nrChannels;

		int _vertexSize;
		unsigned char* data;
		unsigned int _texture;

		unsigned int _modelUniform;

	public:
		Sprite(Renderer* renderer);
		~Sprite();
		void InitTexture();
		void ImportTexture(const char*name);
		void Draw();
		void SetColor(ENTITY_COLOR color);
		void SetColor(float r, float g, float b);
	};
}
#endif