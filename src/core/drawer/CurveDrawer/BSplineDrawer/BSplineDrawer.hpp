#pragma once

#include "core/point/Point.hpp"
#include "core/utils/matrix/Matrix.hpp"

class BSplineDrawer {
public:
  PointVector getPoints(const PointVector& points, const Color& color, bool isClosed);

private:
  void setPoints(const Point &P1, const Point &P2, const Point& P3, const Point& P4);

  Point getPoint(double time, const Color& color) const;

  const Matrix bsplineMatrix = Matrix(
 {{-1, 3, -3, 1},
  {3, -6, 3, 0},
  {-3, 0, 3, 0},
  {1 ,4, 1, 0}});

  Matrix multiplicateMatrix;
};