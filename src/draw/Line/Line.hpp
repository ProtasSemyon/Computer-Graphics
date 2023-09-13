#pragma once

#include "draw/IDrawable.hpp"

class Line: public IDrawable {
public:
  Line() = default;

  Line(const std::vector<std::pair<int, int> > &points);
  
  void draw() override;
};