#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "../Window/Window.h"
#include "../Renderer/Renderer.h"
#include "../Shape/Shape.h"

namespace Engine
{
	class EXPORT_API GameBase
	{
		Renderer* _renderer;
		Windowuwu* _window;

	public:
		GameBase();
		~GameBase();

		int StartEngine(int width, int height, const char* windowName);
		void UpdateEngine();
		void EndEngine();

		Renderer* GetRenderer();
	};
}

#endif;