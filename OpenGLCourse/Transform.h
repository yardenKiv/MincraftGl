#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#define TO_RADIANS 0.01745329252

class Transform
{
public:
	Transform();
	Transform(glm::vec3 newPos);

	glm::mat4 createModleMatrix();

	glm::vec3 pos;
	glm::vec3 rotation;
	glm::vec3 scale;
	

};

