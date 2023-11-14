#pragma once

#include "objects/IObject.hpp"
class HermitCurve : public IObject {
public:
  HermitCurve(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};