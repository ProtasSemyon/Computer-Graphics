#include "HermitCurveMode.hpp"

#include <cmath>

void HermitCurveMode::setPoints(const Point &newStartPoint, const Point &newEndPoint, const Point& newStartPointTangent, const Point& newEndPointTangent) {
  startPoint = newStartPoint;
  endPoint = newEndPoint;
  startPointTangent = newStartPointTangent;
  endPointTangent = newEndPointTangent;

  multiplicateMatrix = Matrix(
    {
    {static_cast<double>(startPoint.x),        static_cast<double>(startPoint.y)},
    {static_cast<double>(endPoint.x),          static_cast<double>(endPoint.y)},
    {static_cast<double>(startPointTangent.x), static_cast<double>(startPointTangent.y)},
    {static_cast<double>(endPointTangent.x),   static_cast<double>(endPointTangent.y)}
    }
  );
}

Point HermitCurveMode::getPoint(double time) const {
  auto mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto result = (mulMatrix * hermitMatrix * multiplicateMatrix).getVector();
  return {(int)result[0], (int)result[1]};
}

std::vector<Point> HermitCurveMode::getCurve(const std::vector<Point>& points) {
  setPoints(points[0], points[1], points[2], points[3]);

  std::vector<Point> result;

  int maxTime = 10000;

  for (int time = 0; time <= maxTime; time++) {
    result.emplace_back(getPoint((double)(time)/maxTime) - endPoint);
  }

  return result;
}

