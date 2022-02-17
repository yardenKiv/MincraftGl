#pragma once

#include <GLFW/glfw3.h>

#include <map>
#include <vector>

class KeyInput
{
public:

	KeyInput(std::vector<int> keysToMonitor);
	bool getIsKeyDown(int key);

private:
	void setIsKeyDown(int key, bool isDown);
	std::map<int, bool> _keys;

    // Workaround for C++ class using a c-style-callback
    public:
    // Must be called before any KeyInput instances will work
    static void setupKeyInputs(Window& window);
    private:
    // The GLFW callback for key events.  Sends events to all KeyInput instances
    static void callback(
        GLFWwindow* window, int key, int scancode, int action, int mods);
    // Keep a list of all KeyInput instances and notify them all of key events
    static std::vector<KeyInput*> _instances;
};

