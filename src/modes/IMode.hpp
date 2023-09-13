#pragma once

#include <GLFW/glfw3.h>
#include "draw/IDrawable.hpp"

class IMode {
public:
  IMode() = default;

  virtual ~IMode() = default;

  virtual void draw() = 0;

  void setWindow(GLFWwindow* newWindow);

protected:
  void setMouseCallback();

  virtual void setMouseCallbackInHeritor() = 0;

  GLFWwindow* window;
};