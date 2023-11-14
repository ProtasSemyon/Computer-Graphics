#pragma once

#include "core/point/Point.hpp"
#include "core/utils/matrix/Matrix.hpp"

class BesieCurveDrawer {
public:
  PointVector getPoints(const PointVector& points, const Color& color);

private:
  void setPoints(const Point &newP1, const Point &newP2, const Point& newP3, const Point& newP4);

  Point getPoint(double time, const Color& color) const;

  const Matrix besieMatrix = Matrix(
 {{-1, 3, -3, 1},
  {3, -6, 3, 0},
  {-3, 3, 0, 0},
  {1 ,0, 0, 0}});

  Matrix multiplicateMatrix;
};