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
  Matrix mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto a = mulMatrix * hermitMatrix * multiplicateMatrix;
  auto b = a.getVector();
  return {0, 0};
}
