#pragma once 

#include <vector>
#include "core/point/Point.hpp"

class IDrawer {
public:
  virtual std::vector<Point> getPoints(const std::vector<Point> &points) = 0;

  virtual ~IDrawer() = default;
};