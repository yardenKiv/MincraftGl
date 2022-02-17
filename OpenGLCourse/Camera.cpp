#include "Camera.h"

Camera::Camera(glm::vec3 newPos)
{
	pos = newPos;
	target = glm::vec3(0, 0, 0);
}

glm::mat4 Camera::createViewMatrix()
{
	return glm::lookAt(pos, target, UP);
}
