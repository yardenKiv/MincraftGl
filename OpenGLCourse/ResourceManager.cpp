#include "ResourceManager.h"



ResourceManager* ResourceManager::getInstance()
{
    if (instance == 0)
    {
        instance = new ResourceManager();
    }

    return instance;
}

void ResourceManager::init(GLFWwindow* newWindow)
{
    window = newWindow;
	programs.insert(std::pair<std::string, GLuint>(DEFAULT_PROGRAM, ShadersCreator::createProgram("vertexShader.glsl", "fragmentShader.glsl")));
}

glm::vec2 ResourceManager::getWindowSize()
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    return glm::vec2(width, height);
}
