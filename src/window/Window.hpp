#pragma once

#include <memory>
#include <string>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "modes/IMode.hpp"
#include "objects/DrawableObjectPool.hpp"

const int WIDTH = 1920;

const int HEIGHT = 1080;

const int FONT_SCALE_MILTIPLICATOR = 2;

class IMode;
class Window {
public:
  Window(const std::string &name, int width = WIDTH, int height = HEIGHT);

  void startMainLoop();

  void setMode(IMode* newMode);

  GLFWwindow* getWindow() const;

  bool getIsMenuOpened() const;

  int getWidth() const;

  int getHeight() const;
  
private:
  GLFWwindow* window;

  IMode* mode = nullptr;

  bool closeCondition();

  void draw() const;

  void drawMenu();

  bool isMenuOpened;

  int width;
  
  int height;

  bool open_about = false;

};