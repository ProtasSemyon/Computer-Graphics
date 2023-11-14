#pragma once

#include "objects/IObject.hpp"

class DDALine : public IObject {
public: 
  DDALine(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};