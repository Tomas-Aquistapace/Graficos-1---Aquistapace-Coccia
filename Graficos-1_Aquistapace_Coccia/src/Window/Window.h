#ifndef WINDOW_H

//#include "GLFW/glfw3.h"
#include "..\Export\Export.h"

struct GLFWmonitor;
struct GLFWwindow;

namespace Window_name 
{
	class EXPORT_API Windowuwu
	{
	public:
		Windowuwu();
		~Windowuwu();
	
		void CreateWindow(int width, int height, const char* title, GLFWmonitor* monitor);
		void DestroyWindow(GLFWwindow* window);
		int WindowShouldClose(GLFWwindow* window);
		void SwapBuffers(GLFWwindow* window);
		void ClearWindow(float r, float g, float b, float a);

	private:
	
	};
}

#endif