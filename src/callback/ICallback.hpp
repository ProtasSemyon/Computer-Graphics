#pragma once 

#include <GLFW/glfw3.h>
class ICallback {
public:
  virtual void mouseCallback(GLFWwindow* window, int button, int action, int mods) = 0;

  virtual void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;

  virtual ~ICallback() = default;
};