#pragma once

#include "objects/IDrawable.hpp"

class Curve : public IDrawable {
public:
  Curve() = default;

  Curve(const std::vector<Point> &points);
};