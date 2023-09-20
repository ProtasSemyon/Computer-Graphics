#include "ParabolaMode.hpp"
#include <algorithm>
#include <cmath>

void ParabolaMode::initialisation(const Point &startPoint, const Point &endPoint) {
  isNegative = endPoint.x - startPoint.x < 0;

  p = std::abs(endPoint.x - startPoint.x);
}

void ParabolaMode::addPoints(std::vector<Point>& points, int x, int y) const {
  if (isNegative) {
    addPoint(points, Point(-x, -y).toScreenPoint(zeroPoint));
    addPoint(points, Point(-x, y).toScreenPoint(zeroPoint));
  } else {
    addPoint(points, Point(x, y).toScreenPoint(zeroPoint));
    addPoint(points, Point(x, -y).toScreenPoint(zeroPoint));
  }
}

int ParabolaMode::countVerticalError(int y, int error) const {
  return error + 2 * y + 1;
}

int ParabolaMode::countHorizontalError(int /*x*/, int error) const {
  return error - 2 * p;
}

int ParabolaMode::countDiagonalError(int /*x*/, int y, int error) const {
  return error + 2 * y + 1 - 2 * p;
}

int ParabolaMode::countStartError() const {
 return - 2 * p + 1;
}

int ParabolaMode::getStartX() const {
  return p / 2;
}

int ParabolaMode::getStartY() const {
  return 0;
}

bool ParabolaMode::isDiagonalOrHorizontal(int error) const {
  return error > 0;
}
  
bool ParabolaMode::isDiagonalOrVertical(int error) const {
  return error < 0;
}

