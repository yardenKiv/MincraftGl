#include <stdio.h>
#include <string.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	GLuint theShader = glCreateShader(shaderType);

	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(theShader, 1, theCode, codeLength);
	glCompileShader(theShader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(theShader, 1024, NULL, eLog);
		fprintf(stderr, "Error compiling the %d shader: '%s'\n", shaderType, eLog);
		return;
	}

	glAttachShader(theProgram, theShader);
}

GLuint CompileShaders(char* vertexShaderSource, char* fragmentShaderSource)
{
	GLuint program = glCreateProgram();

	if (!program)
	{
		printf("Failed to create shader\n");
		return NULL;
	}

	AddShader(program, vertexShaderSource, GL_VERTEX_SHADER);
	AddShader(program, fragmentShaderSource, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(program, sizeof(eLog), NULL, eLog);
		printf("Error linking program: '%s'\n", eLog);
		return NULL;
	}

	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(program, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s'\n", eLog);
		return NULL;
	}

	return program;

}