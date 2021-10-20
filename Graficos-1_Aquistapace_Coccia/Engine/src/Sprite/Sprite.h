
#ifndef SPRITE_H
#define SPRITE_H
#include "..\Export\Export.h"
#include "..\Entity\Entity.h"

namespace Engine
{
	class EXPORT_API Sprite : public Entity
	{
		int width;
		int height;
		int nrChannels;

		unsigned char* data; 
		unsigned int texture;

	public:
		Sprite(Renderer* renderer);
		~Sprite();
		void BindTexture();
		void SetTexParameter();
		void ImportTexture(const char*name);
		void Draw();
		void SetColor(ENTITY_COLOR color);
		void SetColor(float r, float g, float b);
	};
}
#endif

