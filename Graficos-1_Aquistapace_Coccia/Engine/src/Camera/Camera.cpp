#include "Camera.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm\gtc\type_ptr.hpp"

namespace Engine
{
	Camera::Camera()
	{
		//_projection = glm::perspective(glm::radians(45.0f), 1366.0f / 768.0f, 0.1f, 1000.0f);
		_projection = glm::mat4(1.0f);
		_view = glm::mat4(1.0f);
	}

	Camera::~Camera()
	{

	}

	void Camera::UpdateMVP(glm::mat4 model, unsigned int shaderId) //, unsigned int uniformModel, unsigned int uniformView, unsigned int uniformProjection, 
	{
		unsigned int modelInd = glGetUniformLocation(shaderId, "model");
		unsigned int viewInd = glGetUniformLocation(shaderId, "view");
		unsigned int projectionInd = glGetUniformLocation(shaderId, "projection");
		
		glUniformMatrix4fv(modelInd, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(projectionInd, 1, GL_FALSE, glm::value_ptr(_projection));
		glUniformMatrix4fv(viewInd, 1, GL_FALSE, glm::value_ptr(_view));
	}

	void Camera::UseCamera(Shader& shader, glm::mat4 trsCamera)
	{
		//unsigned int transformLoc = glGetUniformLocation(shader.GetShader(), "model");
		//unsigned int projectionLoc = glGetUniformLocation(shader.GetShader(), "projection");
		//unsigned int viewLoc = glGetUniformLocation(shader.GetShader(), "view");
		//glUseProgram(shader.GetShader());
		//glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trsCamera));
		//glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(_MVP.projection));
		//glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(_MVP.view));
	}
}