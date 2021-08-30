#ifndef WINDOW_H
#define WINDOW_H

#include "..\Export\Export.h"

struct GLFWmonitor;
struct GLFWwindow;

namespace Window_name 
{
	class EXPORT_API Windowuwu
	{
		GLFWwindow* _window;
	public:
		Windowuwu();
		~Windowuwu();
	
		int CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor);
		void InitWindow();
		void DestroyWindow();
		int WindowShouldClose();
		void SwapBuffers();
		void ClearWindow(float r, float g, float b, float a);
		GLFWwindow* ReturnWindow();
	};
}

#endif