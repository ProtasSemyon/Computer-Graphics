#include "modes/IMode.hpp"

void IMode::setWindow(GLFWwindow* newWindow) {
  window = newWindow;
  setMouseCallback();
}

void IMode::setMouseCallback() {
  setMouseCallbackInHeritor();
}