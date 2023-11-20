#include "CallbackManager.hpp"
#include <imgui_impl_glfw.h>

std::vector<std::shared_ptr<ICallback>> CallbackManager::callbacks;

void CallbackManager::addObject(const std::shared_ptr<ICallback>& callback) const {
  if(callback) {
    callbacks.emplace_back(callback);
  }
}

void CallbackManager::deleteObject(const std::shared_ptr<ICallback> &callbackAddr) const {
  for (size_t i  = 0; i < callbacks.size(); i++) {
    auto callback = callbacks[i];
    if (callback == callbackAddr) {
      callbacks.erase(callbacks.begin() + i);
      break;
    }
  }
}

CallbackManager& CallbackManager::getInstance() {
  static CallbackManager instance;
  return instance;
}

void CallbackManager::setCallback(GLFWwindow *window) {
  glfwSetMouseButtonCallback(window, CallbackManager::mouseButtonCallback);
  glfwSetKeyCallback(window, CallbackManager::keyboardButtonCallback);
}

void CallbackManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  for (const auto & callback: callbacks) {
    callback->mouseCallback(window, button, action, mods);
  }
}

void CallbackManager::keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  for (const auto & callback: callbacks) {
    callback->keyboardCallback(window, key, scancode, action, mods);
  }
}