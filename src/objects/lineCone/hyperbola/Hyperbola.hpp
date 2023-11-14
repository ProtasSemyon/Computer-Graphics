#pragma once

#include "objects/IObject.hpp"

class Hyperbola : public IObject {
public: 
  Hyperbola(const PointVector& points, bool isHorizontal = true, const Color & color = BLACK);

  PointVector getPointsForDrawing() const override;

private:
  bool isHorizontal;
};