#include "Entity.h"

Entity::Entity(std::string newId, glm::vec3 pos)
{
	id = newId;
	layer = FORGROUND;
	transform = new Transform(pos);
}

