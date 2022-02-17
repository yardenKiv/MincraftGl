#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square(std::string id, float x, float y, float z);
	Square(std::string id, glm::vec3 newPos);
};
