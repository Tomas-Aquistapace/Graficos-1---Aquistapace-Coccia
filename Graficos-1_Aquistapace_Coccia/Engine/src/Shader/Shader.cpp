#include "Shader.h"
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

namespace Engine
{	
	Shader::Shader()
	{
		_vertexShader =
			"#version 330 core\n"
			"layout (location = 0) in vec4 position;\n"

			"uniform mat4 model;\n"
			"in vec3 color;\n"
			"out vec4 vColour;\n"

			"void main()\n"
			"{\n"
			"   gl_Position = model * position;\n"
			"	vColour = vec4(color, 1.0f);\n"
			"}\0";

		_fragmentShader =
			"#version 330 core\n"
			"in vec4 vColour;\n"

			"out vec4 colour;\n"

			"void main()\n"
			"{\n"
			"   colour = vColour;\n"
			"}\n\0";

		_shader = 0;
	}

	Shader::~Shader()
	{

	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		// Si ocurre algun error, se ejecutara esto:
		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

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

	unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
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

	void Shader::SetShader()
	{
		_shader = CreateShader(_vertexShader, _fragmentShader);
	}

	void Shader::ClearShader()
	{
		if (_shader != 0)
		{
			glDeleteProgram(_shader);
			_shader = 0;
		}
	}
	
	unsigned int Shader::GetShader()
	{
		return _shader;
	}

}