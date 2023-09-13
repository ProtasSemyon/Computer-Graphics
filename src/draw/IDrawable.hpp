#pragma once

#include <GLFW/glfw3.h>
#include <vector>

class IDrawable {
public:
  IDrawable() = default;

  IDrawable(const std::vector<std::pair<int, int> >& points);

  virtual void draw() = 0;

  virtual ~IDrawable() = default;

protected:
  std::vector<std::pair<int, int>> points;
};