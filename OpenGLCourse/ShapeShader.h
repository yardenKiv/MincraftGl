#pragma once
#include "Shader.h"

enum ShapeType {TRAINGLE, SQUARE};

class ShapeShader : public Shader
{
public:
	ShapeShader(ShapeType shape);
	int initVertexBuffer(ShapeType shape);

	ShapeType shape;

	
	
};

