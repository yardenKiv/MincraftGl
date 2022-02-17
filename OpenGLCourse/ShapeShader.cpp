#include "ShapeShader.h"

ShapeShader::ShapeShader(ShapeType shape)
{
	this->shape = shape;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	verticesNumber = initVertexBuffer(shape);

	program = ResourceManager::getInstance()->programs.find(DEFAULT_PROGRAM)->second;

	posAttribute = glGetAttribLocation(program, "pos");
	glVertexAttribPointer(posAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttribute);

	modelUniform = glGetUniformLocation(program, "model");
	projectionUniform = glGetUniformLocation(program, "projection");
	viewUniform = glGetUniformLocation(program, "view");
	colorUniform = glGetUniformLocation(program, "ourColor");

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

int ShapeShader::initVertexBuffer(ShapeType shape)
{
	int verticesNumber = 0;

	switch (shape)
	{
	case TRAINGLE:
		verticesNumber = VertexBufferManager::initTringleVertices();
		break;

	case SQUARE:
		verticesNumber = VertexBufferManager::initSquareVertices();
		break;
	}

	return verticesNumber;
}
