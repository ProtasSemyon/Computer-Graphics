#include "modes/IMode.hpp"
#include <iostream>

bool IMode::debugMode = false;

void IMode::setWindow(Window* newWindow) {
  window = newWindow;
  setMouseCallback();
  setKeyCallback();
}

void IMode::setMouseCallback() {
  setMouseCallbackInHeritor();
}

void IMode::changeDebugState() {
  debugMode = !debugMode;
  std::cout << "changed debug state" << std::endl;
}

void IMode::setKeyCallback() {
  glfwSetKeyCallback(window->getWindow(), keyCallback);
}

void IMode::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == DEBUG_MODE_KEY && action == GLFW_PRESS)
    changeDebugState();
}

int IMode::round(float x) {
  return static_cast<int>(x + 0.5f);
}
