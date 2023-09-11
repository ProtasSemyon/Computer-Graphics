#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include "modes/IMode.hpp"

const int WIDTH = 1920;

const int HEIGHT = 1080;

class Window {

public:
  Window(const std::string &name, int width = WIDTH, int height = HEIGHT);

  void startMainLoop();
  
private:
  GLFWwindow* window;

  IMode* mode;

  bool closeCondition();

  void draw() const;
};