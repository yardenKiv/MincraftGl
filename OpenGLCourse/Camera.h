#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>


class Camera
{
public:
	Camera(glm::vec3 newPos);

	glm::vec3 pos;
	glm::vec3 target;
	
	const glm::vec3 UP = glm::vec3(0, 1, 0);

	glm::mat4 createViewMatrix();
};

