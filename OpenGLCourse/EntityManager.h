#pragma once
#include <vector>

#include "Entity.h"

class EntityManager
{
public:
	std::map<std::string, Entity*> entitys;
	
	void addEntity(Entity* entity);


	void update();
	void draw();
};

