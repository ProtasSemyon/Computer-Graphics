#pragma once

#include "callback/ICallback.hpp"
#include <string>

#include <GLFW/glfw3.h>
class IMode : public ICallback{
public:
  void mouseCallback(GLFWwindow* window, int button, int action, int mods) override {} //TODO: remove, add override in derived classes

  void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) override {} //TODO: remove, add override in derived classes
  
private:
  std::string printedStr = "bruhForTest";
};