#include "Game.h"

void Game::start(int window_width, int window_height, std::string window_title)
{
	camera = new Camera(glm::vec3(0, 0, 20));
	

	isRuning = true;

	entityManager = new EntityManager();

	static int check = 0;

	windowWidth = window_width;
	windowHeight = window_height;
	windowTitle = window_title;

	systemInit();
	init();

	while (isRuning && !glfwWindowShouldClose(window))
	{
		if (isPaused)
			continue;

		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		update();
		entityManager->update();
		entityManager->draw();

		glfwSwapBuffers(window);

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	
}



void Game::pause()
{
	isPaused = true;
}
void Game::stop()
{
	isRuning = false;
}

void Game::setWindowSize(int width, int hieght)
{
}

void Game::systemInit()
{

	initGLFW();
	initWindow();

	ResourceManager::getInstance()->init(window);
	ResourceManager::getInstance()->camera = camera;
}
void Game::initWindow()
{
	// Create the window
	window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL);
	if (!window)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		isRuning = false;
	}

	// Get Buffer Size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(window);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(window);
		glfwTerminate();
		return;
	}

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);
}

void Game::initGLFW()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		isRuning = false;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}
