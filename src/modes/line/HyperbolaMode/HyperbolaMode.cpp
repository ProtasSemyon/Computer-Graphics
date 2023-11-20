#include "HyperbolaMode.hpp"
#include "objects/lineCone/hyperbola/Hyperbola.hpp"

const int CHANGE_DRAWING_MODE_KEY = GLFW_KEY_SPACE;

void HyperbolaMode::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == CHANGE_DRAWING_MODE_KEY && action == GLFW_PRESS)
    isHorizontal = !isHorizontal;
} 

std::shared_ptr<IObject> HyperbolaMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<Hyperbola>(points, isHorizontal);
}

