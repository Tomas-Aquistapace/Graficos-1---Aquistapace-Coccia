#include "Renderer.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{
	float vertex[6] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.0f,  0.5f
	};
	//unsigned int vao; // Vertex Array Obj 
	//unsigned int vbo; // Vertex Buffer Obj
	unsigned int buffer; // Vertex Buffer Obj

	//------ SHADER

	unsigned int _shader;

	const char* _vertexShader = 
		"#version 330 core\n"
		"layout (location = 0) in vec4 position;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = position;\n"
		"}\0";
	const char* _fragmentShader = 
		"#version 330 core\n"
		"layout(location = 0) out vec4 color;\n"
		"void main()\n"
		"{\n"
		"   color = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
		"}\n\0";

	//====================================\\

	Renderer::Renderer()
	{		
		//_shader1 = new Shader();
	}

	Renderer::~Renderer()
	{
		//if (_shader1 != NULL)
		//	delete _shader1;

		glDeleteProgram(_shader);
	}

	int Renderer::InitGlew()
	{
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Error in Glew Init" << std::endl;
			return -1;
		}
	}

	void Renderer::CreateBuffer()
	{
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Renderer::CreateShader()
	{
		_shader = CreateShader(_vertexShader, _fragmentShader);
		glUseProgram(_shader);
	}

	void Renderer::DrawRenderer()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(_shader);
		glBindVertexArray(buffer);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	//====================================\\

	unsigned int Renderer::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		// Si ocurre algun error, se ejecutara esto:
		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, & result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)_malloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			
			std::cout << "failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!"
				<< std::endl;
			std::cout << message << std::endl;
			
			glDeleteShader(id);

			return 0;
		}

		return id;
	}

	unsigned int Renderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
}