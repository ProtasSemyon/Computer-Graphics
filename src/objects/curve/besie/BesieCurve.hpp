#pragma once

#include "objects/IObject.hpp"
class BesieCurve : public IObject {
public:
  BesieCurve(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};