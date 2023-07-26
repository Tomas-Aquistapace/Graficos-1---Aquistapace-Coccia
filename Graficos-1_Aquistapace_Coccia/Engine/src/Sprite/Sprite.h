#ifndef SPRITE_H
#define SPRITE_H

#include "..\Export\Export.h"
#include "..\Entity\Entity.h"
#include "..\Animation\Animation.h"
#include "..\TextureImporter\TextureImporter.h"

#include <vector>

namespace Engine
{
	class EXPORT_API Sprite : public Entity
	{
	private:
		float _vertex[36]
		{
			// positions          // colors					// texture coords
			 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
			 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f,   0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f, 0.0f,   0.0f, 1.0f    // top left
		};

		unsigned int _index[6] = 
		{
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
		};

		unsigned int _vao; // Vertex Array Obj
		unsigned int _vbo; // Vertex Buffer Obj
		unsigned int _ebo; // Index Buffer Obj

		int _vertexSize;
		unsigned int _texture;
		unsigned int _modelUniform;

		vector<Animation*> _animations;
		TextureImporter* _textureImporter;

		void InitTexture();

	public:
		Sprite(Renderer* renderer);
		~Sprite();

		void ImportTexture(const char*name);

		void AddAnimation(string id, const ivec2& tileDimensions, float durationInSec, int firstIndex, int lastIndex);
		
		void Draw();
		void DrawFrame(string id, int index);

		void DrawAnimation(string id, float deltaTime);
		void DrawAnimation(int id, float deltaTime);

		Animation* GetAnimation(string id);
		Animation* GetAnimation(int id);

		void SetColor(ENTITY_COLOR color);
		void SetColor(float r, float g, float b);
		void TriggerCollision(Entity* other);
	};
}
#endif