#pragma once

#include "objects/IObject.hpp"

class BSplineCurve : public IObject {
public:
  BSplineCurve(const PointVector& points, bool isClosed, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;

private:
  bool isClosed;
};