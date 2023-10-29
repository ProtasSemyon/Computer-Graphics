#pragma once

#include "modes/curves/ICurveMode.hpp"
#include "core/matrix/Matrix.hpp"
#include "core/point/Point.hpp"

class HermitCurveMode : public ICurveMode {
public:
  void setPoints(const Point &startPoint, const Point &endPoint, const Point& startPointTangent, const Point& endPointTangent);

  Point getPoint(double time) const;

private:
 const Matrix hermitMatrix = Matrix(
 {{2, -2, 1, 1},
  {-3, 3, -2, -1},
  {0, 0, 1, 0},
  {0 ,1, 0, 0}});

  Point startPoint;
  Point endPoint;
  Point startPointTangent;
  Point endPointTangent;

  Matrix multiplicateMatrix;
};