#pragma once

#include <GL/glew.h>
#include <string>
#include <unordered_map>
#include <assert.h>

#include "../maths/maths.h"
//#include "glm/glm.hpp"

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

namespace icarus {
	namespace graphics {

		struct ShaderProgramSource
		{
			std::string VertexSource;
			std::string FragmentSource;
		};

		class Shader
		{
		private:
			std::string m_FilePath;
			unsigned int m_RendererID;
			std::unordered_map<std::string, GLint> m_UniformLocationCache;
		public:
			Shader(const std::string& filepath);
			~Shader();

			void Bind() const;
			void Unbind() const;

			// Set uniforms
			void SetUniform1i(const std::string& name, int value);
			void SetUniform1f(const std::string& name, float value);
			void SetUniform2f(const std::string& name, const maths::Vector2& vector);
			void SetUniform2f(const std::string& name, float v0, float v1);
			void SetUniform3f(const std::string& name, const maths::Vector3& vector);
			void SetUniform3f(const std::string& name, float v0, float v1, float v2);
			void SetUniform4f(const std::string& name, const maths::Vector4& vector);
			void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
			void SetUniformMat4f(const std::string& name, const maths::Matrix4x4& matrix);
		private:
			ShaderProgramSource ParseShader(const std::string& filepath);
			unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
			GLuint CompileShader(GLenum type, const std::string& source);
			unsigned int GetUniformLocation(const std::string& name);
		};

	}
}
