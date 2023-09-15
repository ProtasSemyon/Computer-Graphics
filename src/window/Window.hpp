#pragma once

#include <memory>
#include <string>
#include "modes/IMode.hpp"
#include "draw/DrawableObjectPool.hpp"

const int WIDTH = 1920;

const int HEIGHT = 1080;

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
};