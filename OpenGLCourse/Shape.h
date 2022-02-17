#pragma once
#include "Entity.h"




class Shape : public Entity
{
public:
	Shape(std::string id, ShapeType shapeType, glm::vec3 newPos);

	void update();
	void draw();
	
	glm::vec3 color;


};