#include "Transform.h"

Transform::Transform()
{
	pos = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}

Transform::Transform(glm::vec3 newPos)
{
	pos = newPos;
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}



glm::mat4 Transform::createModleMatrix()
{

	glm::mat4 model(1.0);
	
	model = glm::translate(model, pos);
	model = glm::scale(model, scale);

	model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(1, 0, 0));
	model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 1, 0));
	model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));

	return model;
}



