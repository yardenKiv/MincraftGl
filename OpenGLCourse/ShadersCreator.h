#pragma once
#include <string>

#include "Utilities.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace ShadersCreator
{
	GLuint createProgram(std::string vertexShaderPath, std::string fragmentShaderPath);

	void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
	GLuint compileShaders(std::string vertexShaderSource, std::string fragmentShaderSource);
};

