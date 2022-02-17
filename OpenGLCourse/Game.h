#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Entity.h"
#include "ResourceManager.h"
#include "EntityManager.h"

#include "Camera.h"



#pragma once
class Game
{
protected:


	GLFWwindow* window;
	std::string windowTitle;
	
	EntityManager* entityManager;

	virtual void init() = 0;
	virtual void update() = 0;
	void pause();
	void stop();
	void setWindowSize(int width, int hieght);

public:
	Camera* camera;

	void start(int window_width, int window_height, std::string window_title);

	int windowWidth;
	int windowHeight;

private:
	bool isRuning;
	bool isPaused;

	void initGLFW();
	void systemInit();
	void initWindow();


};

