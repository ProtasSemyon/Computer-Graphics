#include "BSplineDrawer.hpp"

#include <cmath>

void BSplineDrawer::setPoints(const Point &P1, const Point &P2, const Point& P3, const Point& P4) {
  multiplicateMatrix = Matrix(
    {
    {(double)P1.getX(), (double)P1.getY()},
    {(double)P2.getX(), (double)P2.getY()},
    {(double)P3.getX(), (double)P3.getY()},
    {(double)P4.getX(), (double)P4.getY()}
    }
  );
}

Point BSplineDrawer::getPoint(double time, const Color& color) const {
  auto mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto result = ((1.0/6.0) * mulMatrix * bsplineMatrix * multiplicateMatrix).getVector();
  return {(int)result[0], (int)result[1], color};
}

PointVector BSplineDrawer::getPoints(const PointVector& points, const Color& color, bool isClosed) {
  auto usedPoints = points;
  if (isClosed) {
    for (int i = 0; i < 4; i++) {
      usedPoints.emplace_back(usedPoints[i]);
    }
  } else {
    usedPoints.insert(usedPoints.begin(), usedPoints[0]);
    usedPoints.emplace_back(usedPoints[usedPoints.size() - 1]);
  }
  PointVector result;

  for (int i = 0; i < usedPoints.size() - 3; i++) {
    setPoints(usedPoints[i], usedPoints[i + 1], usedPoints[i + 2], usedPoints[i + 3]);

    int maxTime = 1000;

    for (int time = 0; time <= maxTime; time++) {
      result.emplace_back(getPoint((double)(time)/maxTime, color));
    }
  }
  return result;
}
