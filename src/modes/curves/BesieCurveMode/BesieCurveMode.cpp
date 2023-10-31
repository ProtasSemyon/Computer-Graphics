#include "BesieCurveMode.hpp"

#include <cmath>

const int POINT_MULTIPLICATOR = 10;

void BesieCurveMode::setPoints(const Point &newP1, const Point &newP2, const Point& newP3, const Point& newP4) {
  P1 = newP1;
  P2 = newP2;
  P3 = newP3;
  P4 = newP4;

  multiplicateMatrix = Matrix(
    {
    {static_cast<double>(P1.x),        static_cast<double>(P1.y)},
    {static_cast<double>(P2.x),          static_cast<double>(P2.y)},
    {static_cast<double>(P3.x), static_cast<double>(P3.y)},
    {static_cast<double>(P4.x),   static_cast<double>(P4.y)}
    }
  );
}

Point BesieCurveMode::getPoint(double time) const {
  auto mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto result = (mulMatrix * besieMatrix * multiplicateMatrix).getVector();
  return {(int)result[0], (int)result[1]};
}

std::vector<Point> BesieCurveMode::getCurve(const std::vector<Point>& points) {
  setPoints(points[0], points[1], points[2], points[3]);

  std::vector<Point> result;

  auto delta = points[0] - points[2];
  int maxTime = std::max(std::abs(delta.x), std::abs(delta.y)) * POINT_MULTIPLICATOR + 2000;

  for (int time = 0; time <= maxTime; time++) {
    result.emplace_back(getPoint((double)(time)/maxTime));
  }

  return result;
}

std::shared_ptr<ICurveMode> BesieCurveMode::getPtr() {
  return std::shared_ptr<BesieCurveMode>(this);
}
