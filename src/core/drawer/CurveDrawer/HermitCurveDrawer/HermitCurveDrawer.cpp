#include "HermitCurveDrawer.hpp"

#include <cmath>

const int POINT_MULTIPLICATOR = 10;

void HermitCurveDrawer::setPoints(const Point &startPoint, const Point &endPoint, const Point& startPointTangent, const Point& endPointTangent){
  multiplicateMatrix = Matrix(
    {
    {(double)startPoint.getX(),        (double)startPoint.getY()},
    {(double)endPoint.getX(),          (double)endPoint.getY()},
    {(double)startPointTangent.getX(), (double)startPointTangent.getY()},
    {(double)endPointTangent.getX(),   (double)endPointTangent.getY()}
    }
  );
}

Point HermitCurveDrawer::getPoint(double time, const Color& color) const {
  auto mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto result = (mulMatrix * hermitMatrix * multiplicateMatrix).getVector();
  return {(int)result[0], (int)result[1], color};
}

PointVector HermitCurveDrawer::getPoints(const PointVector& points, const Color& color) {
  setPoints(points[0], points[1], points[2], points[3]);

  PointVector result;

  auto delta = points[0] - points[1];
  int maxTime = std::max(std::abs(delta.getX()), std::abs(delta.getY())) * POINT_MULTIPLICATOR + 2000;

  for (int time = 0; time <= maxTime; time++) {
    result.emplace_back(getPoint((double)(time)/maxTime, color) - points[1]);
  }

  return result;
}
