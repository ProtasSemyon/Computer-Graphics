#pragma once

#include <vector>
#include "point/Point.hpp"

class IObject {
public:
  IObject() = default;

  IObject(const std::vector<Point>& points);

  virtual ~IObject() = default;

protected:
  std::vector<Point> points;
};