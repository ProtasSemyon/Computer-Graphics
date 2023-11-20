#pragma once 

#include "modes/line/ILineMode.hpp"

class HyperbolaMode : public ILineMode {
public:
  void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) override;

private:
  std::shared_ptr<IObject> getDrawObject(const PointVector &points) const override;

  bool isHorizontal;
};