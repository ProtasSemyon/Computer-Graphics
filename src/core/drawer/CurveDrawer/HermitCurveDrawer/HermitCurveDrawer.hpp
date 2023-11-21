#pragma once

#include "core/point/Point.hpp"
#include "core/utils/matrix/Matrix.hpp"

class HermitCurveDrawer {
public:
  PointVector getPoints(const PointVector& points, const Color& color);

private:
  void setPoints(const Point &startPoint, const Point &endPoint, const Point& startPointTangent, const Point& endPointTangent);

  Point getPoint(double time, const Color& color) const;

  const Matrix hermitMatrix = Matrix(
 {{2, -2, 1, 1},
  {-3, 3, -2, -1},
  {0, 0, 1, 0},
  {1 ,0, 0, 0}});

  Matrix multiplicateMatrix;
};