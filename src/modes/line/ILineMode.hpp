#pragma once

#include "modes/IMode.hpp"

class ILineMode : public IMode {
public:
  void mouseCallback(GLFWwindow* window, int button, int action, int mods) override;

  void drawInCanvas(std::shared_ptr<Canvas> &canvas, const Point &centerPoint) override;

private:
  virtual std::shared_ptr<IObject> getDrawObject(const PointVector &points) const = 0;

  Point startPoint;
  
  Point endPoint;

  Point screenCenter;

  GLFWwindow* currentWindow;
};