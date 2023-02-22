#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "..\Export\Export.h"
#include "..\Entity\Entity.h"}

#include <vector>

using namespace std;

namespace Engine
{
	class EXPORT_API CollisionManager
	{
		vector<Entity*> _vec;

	public:
		CollisionManager();
		~CollisionManager();

		void AddNewObject(Entity* obj);
		void RemoveObject(Entity* obj);

		bool CheckCollision(Entity* one, Entity* two);
		void CheckAllCollisions();
	};
}
#endif