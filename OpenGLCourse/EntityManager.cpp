#include "EntityManager.h"

void EntityManager::addEntity(Entity* entity)
{
	entitys.insert(std::pair<std::string, Entity*>(entity->id, entity));
}

void EntityManager::update()
{
	for (int currLayer = BACKGROUND; currLayer != Last; currLayer++)
	{
		for (auto const& currEntity : entitys) {
			if (currEntity.second->layer == currLayer)
				currEntity.second->update();
		}
	}
}

void EntityManager::draw()
{
	for (int currLayer = BACKGROUND; currLayer != Last; currLayer++)
	{
		for (auto const& currEntity : entitys) {
			if (currEntity.second->layer == currLayer)
				currEntity.second->draw();
		}
	}
}
