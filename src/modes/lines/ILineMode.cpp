#include "modes/lines/ILineMode.hpp"
#include "objects/Line/Line.hpp"
#include "core/objectPool/ObjectPool.hpp"
#include <iostream>

bool ILineMode::startDrawing = false;

bool ILineMode::startDrawingDebug = false;

bool ILineMode::selectFirstPoint = false;

Point ILineMode::startPoint;

Point ILineMode::endPoint;

std::vector<Point> ILineMode::currentLine;

const int DEBUG_NEXT_STEP = GLFW_KEY_ENTER;

void ILineMode::draw() {  
  if (window->getIsMenuOpened()) {
    return;
  }
  
  if (startDrawing) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window->getWindow(), &xpos, &ypos);
    currentDrawObject = std::make_shared<Line>(getLine(startPoint, {(int)xpos, (int)ypos}));
    currentDrawObject->draw();
  }

  if (startDrawingDebug) {
    currentLine = getLine(startPoint, endPoint);
    int drawIndex = -1;
    std::vector<Point> lineForDraw = {};
    while(lineForDraw.size() <= currentLine.size()) {
      if (glfwGetKey(window->getWindow(), DEBUG_NEXT_STEP) == GLFW_PRESS) {
        drawIndex++;
        lineForDraw.emplace_back(currentLine[drawIndex]);
        std::cerr << "x: " << currentLine[drawIndex].x << " y: " << currentLine[drawIndex].y << std::endl;
      }
      if (glfwGetKey(window->getWindow(), DEBUG_MODE_KEY) == GLFW_PRESS) {
        break;
      }
      currentDrawObject = std::make_shared<Line>(lineForDraw);
      currentDrawObject->draw();

      glfwSwapBuffers(window->getWindow());
		  glfwPollEvents();
    }
    startDrawingDebug = false;
    ObjectPool::getInstance().addObject(currentDrawObject);
  }
}

void ILineMode::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
  if (!debugMode) {
    mouseButtonCallbackNoDebug(window, button, action, mods);
  } else {
    if (!startDrawingDebug) {
      mouseButtonCallbackDebug(window, button, action, mods);
    }
  }
}

void ILineMode::setMouseCallbackInHeritor() {
  glfwSetMouseButtonCallback(window->getWindow(), ILineMode::mouseButtonCallback);
}

void ILineMode::mouseButtonCallbackNoDebug(GLFWwindow* window, int button, int action, int /*mods*/) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    startDrawing = true;
    startPoint = {(int)xpos, (int)ypos};
  }

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    startDrawing = false;
    ObjectPool::getInstance().addObject(currentDrawObject);
  }
}

void ILineMode::mouseButtonCallbackDebug(GLFWwindow* window, int button, int action, int /*mods*/) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    selectFirstPoint = !selectFirstPoint;
    if (selectFirstPoint) {
      startPoint = {(int)xpos, (int)ypos};
    } else {
      endPoint = {(int)xpos, (int)ypos};
      startDrawingDebug = true;
    }
  }
}



