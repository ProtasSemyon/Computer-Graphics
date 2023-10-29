#pragma once

#include <GLFW/glfw3.h>

#include "window/Window.hpp"

const int DEBUG_MODE_KEY = GLFW_KEY_D;

class Window;

class IMode {
public:
  IMode() = default;

  virtual ~IMode() = default;

  virtual void draw() = 0;

  void setWindow(Window* newWindow);

  static void changeDebugState();

protected:
  void setMouseCallback();

  void setKeyCallback();

  virtual void setMouseCallbackInHeritor() = 0;

  Window* window;

  static bool debugMode;

  static int round(float x);

private:
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};