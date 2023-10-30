#pragma once

#include "core/refPoint/RefPoint.hpp"
#include "modes/IDrawer.hpp"
#include "modes/IMode.hpp"

const int EXIT_MODE_KEY = GLFW_KEY_ENTER;

class EditorMode : public IMode {
public:
  EditorMode(const std::shared_ptr<IEditable>& editObj, const std::shared_ptr<IMode> &modeObj);

  void draw() override;

  void setMouseCallbackInHeritor() override;

  static std::vector<RefPoint> refPoints;

  static std::vector<Point> points;

private:
  void setKeyCallback() override;

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  std::shared_ptr<IDrawer> drawer;

  static RefPoint * pressedPoint;

  static bool pressed;

  static bool closed;

  std::shared_ptr<IMode> returnMode;
};