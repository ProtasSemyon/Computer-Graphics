#pragma once

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

private:
  void draw();

  void drawImGui();

  void drawMenu();

  ImVec2 getMenuSize();

  GLFWwindow* window;

  int width;
  
  int height;

};