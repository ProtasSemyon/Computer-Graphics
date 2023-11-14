#pragma once

#include "objects/IObject.hpp"

class WuLine : public IObject {
public: 
  WuLine(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};