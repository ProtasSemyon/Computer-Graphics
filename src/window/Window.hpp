#pragma once

#include <memory>
#include <string>
#include "modes/IMode.hpp"
#include "draw/DrawableObjectPool.hpp"

const int WIDTH = 400;

const int HEIGHT = 400;

class Window {
public:
  Window(const std::string &name, int width = WIDTH, int height = HEIGHT);

  void startMainLoop();

  void setMode(IMode* newMode);
  
private:
  GLFWwindow* window;

  IMode* mode;

  bool closeCondition();

  void draw() const;

  void drawMenu();
};