#pragma once

#include "modes/IMode.hpp"

class ILineMode: public IMode {
public:
  ILineMode() = default;

  void draw() override;

private:
  void setMouseCallbackInHeritor() override;

  virtual std::vector<std::pair<int, int> > getLine(std::pair<int, int> startPoint, std::pair<int, int> endPoint) = 0;

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  static void mouseButtonCallbackNoDebug(GLFWwindow* window, int button, int action, int mods);

  static void mouseButtonCallbackDebug(GLFWwindow* window, int button, int action, int mods);

  static bool startDrawing;

  static bool selectFirstPoint;

  static bool startDrawingDebug;

  static std::pair<int, int> startPoint;

  static std::pair<int, int> endPoint;

  static std::vector<std::pair<int, int> > currentLine;
};

