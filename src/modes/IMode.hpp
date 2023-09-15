#pragma once

#include <GLFW/glfw3.h>
#include "draw/IDrawable.hpp"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

const int DEBUG_MODE_KEY = GLFW_KEY_D;

class IMode {
public:
  IMode() = default;

  virtual ~IMode() = default;

  virtual void draw() = 0;

  void setWindow(GLFWwindow* newWindow);

protected:
  void setMouseCallback();

  void setKeyCallback();

  virtual void setMouseCallbackInHeritor() = 0;

  static void changeDebugState();

  GLFWwindow* window;

  static bool debugMode;

private:
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};