#pragma once

#include "objects/IObject.hpp"

class Parabola : public IObject {
public: 
  Parabola(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};