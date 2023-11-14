#include "BesieCurveDrawer.hpp"

#include <cmath>

const int POINT_MULTIPLICATOR = 10;

void BesieCurveDrawer::setPoints(const Point &P1, const Point &P2, const Point& P3, const Point& P4) {
  multiplicateMatrix = Matrix(
    {
    {(double)P1.getX(), (double)P1.getY()},
    {(double)P2.getX(), (double)P2.getY()},
    {(double)P3.getX(), (double)P3.getY()},
    {(double)P4.getX(), (double)P4.getY()}
    }
  );
}

Point BesieCurveDrawer::getPoint(double time, const Color& color) const {
  auto mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto result = (mulMatrix * besieMatrix * multiplicateMatrix).getVector();
  return {(int)result[0], (int)result[1], color};
}

PointVector BesieCurveDrawer::getPoints(const PointVector& points, const Color& color) {
  setPoints(points[0], points[1], points[2], points[3]);

  PointVector result;

  auto delta = points[0] - points[2];
  int maxTime = std::max(std::abs(delta.getX()), std::abs(delta.getY())) * POINT_MULTIPLICATOR + 2000;

  for (int time = 0; time <= maxTime; time++) {
    result.emplace_back(getPoint((double)(time)/maxTime, color));
  }

  return result;
}
