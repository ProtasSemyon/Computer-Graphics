#pragma once

#include "core/point/Point.hpp"
#include <vector>

class IObject {
public:
  IObject(const PointVector& points, const Color &color = BLACK);
  
  virtual PointVector getPointsForDrawing() const = 0;

  virtual ~IObject() = default;

protected:
  PointVector basePoints;

  Color color;
};