#pragma once 

#include "modes/IMode.hpp"

class BresenhemLineMode : public IMode {
public:
  void mouseCallback(GLFWwindow* window, int button, int action, int mods) override;

  void drawInCanvas(std::shared_ptr<Canvas> &canvas) override;

private:
  bool startDrawing;

  Point startPoint;
  
  Point endPoint;

  GLFWwindow* currentWindow;
};