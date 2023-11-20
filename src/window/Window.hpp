#pragma once

#include "window/canvas/Canvas.hpp"
#include <memory>
#include <string>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>


const int WIDTH = 1920;

const int HEIGHT = 1080;

const float FONT_SCALE_MILTIPLICATOR = 2;

class Window {
public:
  Window(const std::string &name, int width = WIDTH, int height = HEIGHT);

  void startMainLoop();

  bool getIsMenuOpened() const;

  int getWidth();

  int getHeight();

  GLFWwindow *getWindow();

private:
  static std::string formatForOutput(const std::string& str);

  void draw();

  void drawImGui();

  void drawMenu();

  void updateScreenCenter();

  static void drawAbout();

  ImVec2 getMenuSize();

  void checkSize();

  std::shared_ptr<Canvas> canvas;

  GLFWwindow* window;

  int width;
  
  int height;

  int oldWidth;

  int oldHeight;

  bool isMenuOpened;

  Point screenCenter;
};