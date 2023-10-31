#pragma once

#include "modes/curves/ICurveMode.hpp"
#include "core/matrix/Matrix.hpp"
#include "core/point/Point.hpp"

class BesieCurveMode : public ICurveMode {
public:
  std::vector<Point> getCurve(const std::vector<Point>& points) override;

private:
  std::shared_ptr<ICurveMode> getPtr() override;

  void setPoints(const Point &newP1, const Point &newP2, const Point& newP3, const Point& newP4);

  Point getPoint(double time) const;

  const Matrix besieMatrix = Matrix(
 {{-1, 3, -3, 1},
  {3, -6, 3, 0},
  {-3, 3, 0, 0},
  {1 ,0, 0, 0}});

  Point P1;
  Point P2;
  Point P3;
  Point P4;

  Matrix multiplicateMatrix;
};