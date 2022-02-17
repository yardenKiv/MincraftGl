#include "Traingle.h"

Traingle::Traingle(std::string id, float x, float y, float z) : Shape(id, TRAINGLE, glm::vec3(x, y, z))
{
}

Traingle::Traingle(std::string id, glm::vec3 newPos) : Shape(id, TRAINGLE, newPos)
{
}

