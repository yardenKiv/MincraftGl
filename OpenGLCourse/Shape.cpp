#include "Shape.h"



Shape::Shape(std::string id, ShapeType shapeType, glm::vec3 newPos) : Entity(id, newPos)
{
	shader = new ShapeShader(shapeType);
	color = WHITE;

}

void Shape::update()
{
}

void Shape::draw()
{




	glUseProgram(shader->program);
	int width = (GLfloat)ResourceManager::getInstance()->getWindowSize().x;
	int height = (GLfloat)ResourceManager::getInstance()->getWindowSize().y;

	glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

	glUniformMatrix4fv(shader->projectionUniform, 1, GL_FALSE, glm::value_ptr(proj));
	glUniformMatrix4fv(shader->viewUniform, 1, GL_FALSE, glm::value_ptr(ResourceManager::getInstance()->camera->createViewMatrix()));
	glUniformMatrix4fv(shader->modelUniform, 1, GL_FALSE, glm::value_ptr(transform->createModleMatrix()));





	glUniform4f(shader->colorUniform, color.x, color.y, color.z, 1);

	glBindVertexArray(shader->VAO);
	glDrawArrays(GL_TRIANGLES, 0, shader->verticesNumber);

	glBindVertexArray(0);
	glUseProgram(0);
}







