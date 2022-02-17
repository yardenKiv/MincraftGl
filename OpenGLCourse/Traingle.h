#pragma once
#include "Shape.h"

class Traingle : public Shape
{
public:
	Traingle(std::string id, float x, float y, float z);
	Traingle(std::string id, glm::vec3 newPos);

};

