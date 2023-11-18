#pragma once

#include "callback/ICallback.hpp"
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>

class CallbackManager {
public:
  void addObject(const std::shared_ptr<ICallback>& callback) const;

  void deleteObject(const std::shared_ptr<ICallback>& callbackAddr) const;

  static CallbackManager& getInstance();

  static void setCallback(GLFWwindow *window);

private:
  static std::vector<std::shared_ptr<ICallback>> callbacks;

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  static void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  CallbackManager() = default;
  CallbackManager(const CallbackManager&) = default;
  CallbackManager& operator=(CallbackManager&) = default;
};
