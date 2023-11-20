#pragma once

#include "callback/ICallback.hpp"
#include "core/point/Point.hpp"
#include "window/canvas/Canvas.hpp"
#include <string>

#include <GLFW/glfw3.h>
class IMode : public ICallback{
public:
  void mouseCallback(GLFWwindow* window, int button, int action, int mods) override;

  void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) override;

  virtual void drawInCanvas(std::shared_ptr<Canvas> &canvas, const Point &centerPoint) = 0;
};