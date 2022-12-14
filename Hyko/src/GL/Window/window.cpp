#include "window.h"

#include "../Engine/System/Time.h"

#include <iostream>

GLFWwindow* Window::m_window;

void Window::setupVariebles(int width, int height, std::string title, const int GLMajorVersion, const int GLMinorVersion)
{
	m_WindowData.Width = width;
	m_WindowData.Height = height;
	m_WindowData.Title = title;
	m_WindowData.GLMajorVersion = GLMajorVersion;
	m_WindowData.GLMinorVersion = GLMinorVersion;
}

void Window::setupHints(const int GLMajorVersion, const int GLMinorVersion)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLMajorVersion); // set opengl major version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLMinorVersion); // set opengl minor version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // set opengl core profile
}

void Window::setupGLAD()
{
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); // installing glad (modern opengl functions)
}

Window::Window(std::string title, int width, int height, const int GLMajorVersion, const int GLMinorVersion) {
	setupVariebles(width, height, title, GLMajorVersion, GLMinorVersion);

	glfwInit(); // init glfw
	
	setupHints(GLMajorVersion, GLMinorVersion);

	m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr); // creating window
	glfwMakeContextCurrent(m_window);

	glfwSetWindowSizeCallback(m_window, viewportResizeCallback);

	setupGLAD();
}

Window::~Window()
{
	glfwTerminate();
	glfwDestroyWindow(m_window);
}

void Window::updateViewportSizeCallback(GLFWwindow *window, int width, int height)
{
	viewportResizeCallback(window, width, height);
}

int Window::getWindowWidth(GLFWwindow* window)
{
	int w = 0;

	glfwGetWindowSize(window, &w, nullptr);

	return w;
}

int Window::getWindowHeight(GLFWwindow* window)
{
	int h = 0;

	glfwGetWindowSize(window, nullptr, &h);

	return h;
}

void Window::setVSync(bool state)
{
	switch (state) {
	case true:
		glfwSwapInterval(1);
		break;
	case false:
		glfwSwapInterval(0);
		break;
	}
}

void viewportResizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
