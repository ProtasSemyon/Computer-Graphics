#pragma once

#include <GLFW/glfw3.h>

#include "core/refPoint/RefPoint.hpp"
#include "window/Window.hpp"
#include "objects/IDrawable.hpp"

const int DEBUG_MODE_KEY = GLFW_KEY_D;

class Window;
class IEditable;

class IMode {
public:
  IMode() = default;

  virtual ~IMode() = default;

  virtual void draw() = 0;

  void setWindow(Window* newWindow);

  static void changeDebugState();

  virtual void finishDraw(const std::vector<Point> &objPoints, const std::vector<RefPoint> &objRefPoints) {}

protected:
  void setMouseCallback();

  virtual void setKeyCallback();

  virtual void setMouseCallbackInHeritor() = 0;

  virtual void startEditMode(const std::shared_ptr<IEditable>& objForEdit) {}

  Window* window;

  static bool debugMode;

  static int round(float x);

  static std::shared_ptr<IDrawable> currentDrawObject;

private:
  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};