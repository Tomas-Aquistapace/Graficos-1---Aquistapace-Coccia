#ifndef SHADER_H
#define SHADER_H

#include <string>
#include "..\Export\Export.h"

namespace Engine
{
	class EXPORT_API Shader
	{
	private:
		unsigned int _shader;

		const char* _vertexShader;
		const char* _fragmentShader;

		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	
	public:
		Shader();
		~Shader();

		void SetShader();
		void ClearShader();

		unsigned int GetShader();
	};
}

#endif