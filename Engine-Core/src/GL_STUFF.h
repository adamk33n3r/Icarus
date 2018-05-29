#pragma once

#include <iostream>
#include <assert.h>
#include <GL/glew.h>

inline void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogCall(const char* function, const char* file, int line)
{
	GLenum error;
	while ((error = glGetError()) != GL_NO_ERROR) {
		std::cout << "GL Error: (0x" << std::hex << error << std::dec << "): " << function << " " << file << ":" << line << std::endl;
		return false;
	}
	return true;
}

#define ASSERT(x) if (!(x)) assert(false);
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
