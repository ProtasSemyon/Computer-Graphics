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

  static bool startDrawing;

  static std::pair<int, int> startPoint;

  static std::vector<std::pair<int, int> > currentLine;
};

