#include <vector>
#include <iostream>
#include <string>
#include <map>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "ShadersCreator.h"
#include "VertexBufferManager.h"
#include "Camera.h"

#define DEFAULT_PROGRAM "defaultShaders"

#pragma once
class ResourceManager
{
private:
	ResourceManager() {};
	inline static ResourceManager* instance;

	GLFWwindow* window;

public:
	static ResourceManager* getInstance();

	void init(GLFWwindow* newWindow);
	std::map<std::string, GLuint> programs;

	glm::vec2 getWindowSize();

	Camera* camera;
	

};

