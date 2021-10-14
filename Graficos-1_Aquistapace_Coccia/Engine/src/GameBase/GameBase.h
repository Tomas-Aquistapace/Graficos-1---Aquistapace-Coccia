#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "../Window/Window.h"
#include "../Renderer/Renderer.h"
#include "../Shape/Shape.h"
#include "../Input/Input.h"
#include "../Time/Time.h"

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
		void UpdateEngine(float r, float g, float b, float a);
		void EndEngine();

		virtual void Update(float deltatime) = 0;

		void SetCamera(CameraType type, float near, float far);
		Renderer* GetRenderer();
	};
}

#endif;