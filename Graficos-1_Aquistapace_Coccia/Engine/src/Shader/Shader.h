#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "..\Export\Export.h"

namespace Engine
{
	class EXPORT_API Shader
	{
	private:
		const char* _vertexShader;
		const char* _fragmentShader;

	public:
		Shader();
		~Shader();

		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

	};
}

#endif