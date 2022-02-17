#pragma once
#include "ShapeShader.h"
#include "Transform.h"

#include "Colors.h"


enum Layer { BACKGROUND, FORGROUND, FRONTGROUND, UI , Last};

class Entity
{
public:
	Entity(std::string newId, glm::vec3 pos);

	std::string id;
	Transform* transform;
	Layer layer;
	
	Shader* shader;
	
	virtual void update() = 0;
	virtual void draw() = 0;
};

