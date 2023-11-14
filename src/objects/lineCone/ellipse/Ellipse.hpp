#pragma once

#include "objects/IObject.hpp"

class Ellipse : public IObject {
public: 
  Ellipse(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};