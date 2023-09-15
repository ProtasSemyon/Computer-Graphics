#pragma once

#include "modes/IMode.hpp"
#include "core/Point.hpp"

class ILineMode: public IMode {
public:
  ILineMode() = default;

  void draw() override;

private:
  void setMouseCallbackInHeritor() override;

  virtual std::vector<Point> getLine(Point startPoint, Point endPoint) = 0;

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  static void mouseButtonCallbackNoDebug(GLFWwindow* window, int button, int action, int mods);

  static void mouseButtonCallbackDebug(GLFWwindow* window, int button, int action, int mods);

  static bool startDrawing;

  static bool selectFirstPoint;

  static bool startDrawingDebug;

  static Point startPoint;

  static Point endPoint;

  static std::vector<Point> currentLine;
};

