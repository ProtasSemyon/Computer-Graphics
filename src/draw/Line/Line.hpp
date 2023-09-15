#pragma once

#include "draw/IDrawable.hpp"

class Line: public IDrawable {
public:
  Line() = default;

  Line(const std::vector<Point> &points);
  
  void draw() override;
};