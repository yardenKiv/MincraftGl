#include "MyGame.h"

void MyGame::init()
{
	Shape* a = new Traingle("aaa", 10, 0, 0);
	this->entityManager->addEntity(a);
}

void MyGame::update()
{
	
}