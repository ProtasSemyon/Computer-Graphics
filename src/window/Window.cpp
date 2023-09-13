#include "Window.hpp"
#include <stdexcept>


Window::Window(const std::string &name, int width, int height) {
  if( !glfwInit() ){
    throw std::invalid_argument("Failed to initialize GLFW");
	}

  window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
	if( window == nullptr ){
		glfwTerminate();
    throw std::invalid_argument("Failed to open GLFW window");
	}
	glfwMakeContextCurrent(window);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH - 1, HEIGHT - 1, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void Window::startMainLoop() {
  do{		
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	} 
	while(!closeCondition());

	glfwTerminate();
}

bool Window::closeCondition() {
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  return glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS || glfwWindowShouldClose(window) != 0;
}

void Window::draw() const {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
	
	DrawableObjectPool::getInstance().draw();
	if (mode) {
		mode->draw();
	}
}

void Window::setMode(IMode* newMode) {
	mode = newMode;
	mode->setWindow(window);
}
