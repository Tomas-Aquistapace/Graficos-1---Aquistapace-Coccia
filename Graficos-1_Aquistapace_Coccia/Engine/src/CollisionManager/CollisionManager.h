#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "..\Export\Export.h"
#include "..\Sprite\Sprite.h"
#include "..\Shape\Shape.h"
//#include "..\Entity\Entity.h"

namespace Engine
{
	class EXPORT_API CollisionManager
	{
		
	public:
		//CollisionManager();
		//~CollisionManager();

		bool CheckCollision(Sprite& one, Sprite& two);
		bool CheckCollision(Shape& one, Shape& two);

	};
}
#endif