#include "Square.h"

Square::Square(std::string id, float x, float y, float z) : Shape(id, SQUARE, glm::vec3(x, y, z))
{
}

Square::Square(std::string id, glm::vec3 newPos) : Shape(id, SQUARE, newPos)
{
}

