#include "BresenhemLineMode.hpp"
#include "objectPool/ObjectPool.hpp"
#include "objects/line/bresenhem/BresenhemLine.hpp"

void BresenhemLineMode::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    currentWindow = window;
    startPoint = {(int)xpos, (int)ypos};
  }

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    currentWindow = nullptr;
    endPoint = {(int)xpos, (int)ypos};    
    ObjectPool::getInstance().addObject(std::make_shared<BresenhemLine>(PointVector{startPoint, endPoint}));
  }
}

void BresenhemLineMode::drawInCanvas(std::shared_ptr<Canvas>& canvas) {
  if (currentWindow){
    double xpos;
    double ypos;
    glfwGetCursorPos(currentWindow, &xpos, &ypos);
    endPoint = {(int)xpos, (int)ypos};
    canvas->setDynamicObj(std::make_shared<BresenhemLine>(PointVector{startPoint, endPoint}));
  } else {
    canvas->resetDynamicObj();
  }    
}




