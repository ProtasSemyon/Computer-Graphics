#pragma once

#include "objects/IObject.hpp"

class BresenhemLine : public IObject {
public: 
  BresenhemLine(const PointVector& points, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;
};