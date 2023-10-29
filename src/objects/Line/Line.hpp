#pragma once

#include "objects/IDrawable.hpp"

class Line: public IDrawable {
public:
  Line() = default;

  Line(const std::vector<Point> &points);
};