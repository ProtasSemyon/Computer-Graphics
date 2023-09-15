#include "modes/lines/ILineMode.hpp"
#include "draw/Line/Line.hpp"
#include "draw/DrawableObjectPool.hpp"
#include <iostream>

bool ILineMode::startDrawing = false;

bool ILineMode::startDrawingDebug = false;

bool ILineMode::selectFirstPoint = false;

Point ILineMode::startPoint;

Point ILineMode::endPoint;

std::vector<Point> ILineMode::currentLine;

const int DEBUG_NEXT_STEP = GLFW_KEY_ENTER;

void ILineMode::draw() {  
  if (startDrawing) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    currentLine = getLine(startPoint, {(int)xpos, (int)ypos});

    glBegin( GL_POINTS );
    for(const auto& [x, y, color] : currentLine) {
      glColor4f(color.r, color.g, color.b, color.a);
      glVertex2i(x, y);
    }
    glEnd();
  }

  if (startDrawingDebug) {
    currentLine = getLine(startPoint, endPoint);
    int drawIndex = -1;
    std::vector<Point> lineForDraw = {};
    while(lineForDraw.size() <= currentLine.size()) {
      if (glfwGetKey(window, DEBUG_NEXT_STEP) == GLFW_PRESS) {
        drawIndex++;
        lineForDraw.emplace_back(currentLine[drawIndex]);
      }
      if (glfwGetKey(window, DEBUG_MODE_KEY) == GLFW_PRESS) {
        break;
      }
      glBegin( GL_POINTS );
        for(const auto& [x, y, color] : lineForDraw) {
          glColor4f(color.r, color.g, color.b, color.a);
          glVertex2i(x, y);
        }
      glEnd();

      glfwSwapBuffers(window);
		  glfwPollEvents();
    }
    startDrawingDebug = false;
    DrawableObjectPool::getInstance().addObject(new Line(lineForDraw));
  }
}

void ILineMode::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  if (!debugMode) {
    mouseButtonCallbackNoDebug(window, button, action, mods);
  } else {
    if (!startDrawingDebug) {
      mouseButtonCallbackDebug(window, button, action, mods);
    }
  }
}

void ILineMode::setMouseCallbackInHeritor() {
  glfwSetMouseButtonCallback(window, ILineMode::mouseButtonCallback);
}

void ILineMode::mouseButtonCallbackNoDebug(GLFWwindow* window, int button, int action, int /*mods*/) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    std::cerr << "x: " << xpos << " y: " << ypos << std::endl;

    startDrawing = true;
    startPoint = {(int)xpos, (int)ypos};
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

void ILineMode::mouseButtonCallbackDebug(GLFWwindow* window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    std::cerr << "x: " << xpos << " y: " << ypos << std::endl;

    selectFirstPoint = !selectFirstPoint;
    if (selectFirstPoint) {
      startPoint = {(int)xpos, (int)ypos};
    } else {
      endPoint = {(int)xpos, (int)ypos};
      startDrawingDebug = true;
    }
    //DrawableObjectPool::getInstance().addObject(new Line(currentLine));
  }
}



