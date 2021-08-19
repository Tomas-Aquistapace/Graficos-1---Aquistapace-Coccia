#ifndef WINDOW_H

#include "GLFW/glfw3.h"
#include "..\Export\Export.h"

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


	private:
	
	};
}

#endif