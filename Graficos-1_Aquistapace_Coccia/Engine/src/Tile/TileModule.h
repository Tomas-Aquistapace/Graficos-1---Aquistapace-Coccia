#ifndef TILEMODULE_H
#define TILEMODULE_H

#include "..\Export\Export.h"
#include "glm/glm/glm.hpp"

using namespace glm;

namespace Engine
{
	struct  TileModule
	{
		int _tileFrame = 0;
		bool _collider = false;

		TileModule() {}

		TileModule(int tile, bool coll)
		{
			_tileFrame = tile;
			_collider = coll;
		}
	};

	//class EXPORT_API TileModule
	//{
	//
	//
	//
	//};
}

#endif