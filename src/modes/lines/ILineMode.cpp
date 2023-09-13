#include "modes/lines/ILineMode.hpp"
#include "draw/Line/Line.hpp"
#include "draw/DrawableObjectPool.hpp"
#include <iostream>

bool ILineMode::startDrawing = false;

std::pair<int, int> ILineMode::startPoint = {0,0};

std::vector<std::pair<int, int> > ILineMode::currentLine = {};

void ILineMode::draw() {  
  if (startDrawing) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    currentLine = getLine(startPoint, {xpos, ypos});
    std::cout << currentLine.size() << std::endl;

    glBegin( GL_POINTS );
    for(const auto& [x, y] : currentLine) {
      glVertex2i(x, y);
    }
    glEnd();
  }
}

void ILineMode::mouseButtonCallback(GLFWwindow* window, int button, int action, int /*mods*/) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    std::cerr << "x: " << xpos << " y: " << ypos << std::endl;

    startDrawing = true;
    startPoint = std::make_pair(xpos, ypos);
  }

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    std::cerr << "x: " << xpos << " y: " << ypos << std::endl;

    startDrawing = false;
    DrawableObjectPool::getInstance().addObject(new Line(currentLine));
  }
}

void ILineMode::setMouseCallbackInHeritor() {
  glfwSetMouseButtonCallback(window, ILineMode::mouseButtonCallback);
}

