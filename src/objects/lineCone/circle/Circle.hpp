#pragma once

#include "objects/IObject.hpp"

class Circle : public IObject {
public: 
  Circle(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};