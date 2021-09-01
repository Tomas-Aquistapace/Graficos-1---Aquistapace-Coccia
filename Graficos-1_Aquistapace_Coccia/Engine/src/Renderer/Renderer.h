#ifndef RENDERER_H
#define RENDERER_H

#include "..\Export\Export.h"

namespace Engine
{
	class EXPORT_API Renderer
	{
	public:
		Renderer();
		~Renderer();
		
		int InitGlfw();
		int InitGlew();
		void CreateBuffer();
		void DrawRenderer();
	};
}
#endif