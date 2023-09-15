#pragma once

#include <GLFW/glfw3.h>
#include <vector>

#include "core/Point.hpp"

//TODO: add support of colors. For example, core file with Point structure

class IDrawable {
public:
  IDrawable() = default;

  IDrawable(const std::vector<Point>& points);

  virtual void draw() = 0;

  virtual ~IDrawable() = default;

protected:
  std::vector<Point> points;
};