#pragma once
#include <stdio.h>
#include <string>
#include <map>

#include "Utilities.h"
#include "ResourceManager.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Shader
{
public:
	Shader();
	GLuint program;
	GLuint VAO;
	int verticesNumber;

	GLint modelUniform;
	GLint projectionUniform;
	GLuint viewUniform;
	GLuint colorUniform;

	GLint posAttribute;

	
};

