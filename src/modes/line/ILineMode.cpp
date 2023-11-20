#include "ILineMode.hpp"
#include "core/utils/Utils.hpp"
#include "objectPool/ObjectPool.hpp"
#include <iostream>



void ILineMode::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    if (screenCenter.getX() == 0 && screenCenter.getY() == 0) {
      int xSize;
      int ySize;
      glfwGetWindowSize(window, &xSize, &ySize);
      screenCenter = Point(xSize / 2, ySize / 2);
    }
    currentWindow = window;
    startPoint = screenPointToSystemPoint({(int)xpos, (int)ypos}, screenCenter);
    std::cout << startPoint.getX() << " " << startPoint.getY() << " " << screenCenter.getX() << " " << screenCenter.getY() << std::endl;
  }

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    currentWindow = nullptr;
    endPoint = screenPointToSystemPoint({(int)xpos, (int)ypos}, screenCenter);    
    ObjectPool::getInstance().addObject(getDrawObject(PointVector{startPoint, endPoint}));
  }
}

void ILineMode::drawInCanvas(std::shared_ptr<Canvas>& canvas, const Point &centerPoint) {
  screenCenter = centerPoint;
  if (currentWindow){
    double xpos;
    double ypos;
    glfwGetCursorPos(currentWindow, &xpos, &ypos);
    endPoint = screenPointToSystemPoint({(int)xpos, (int)ypos}, centerPoint);
    canvas->setDynamicObj(getDrawObject(PointVector{startPoint, endPoint}));
  } else {
    canvas->resetDynamicObj();
  }    
}