#include "ParabolaDrawer.hpp"
#include <algorithm>
#include <cmath>

void ParabolaDrawer::initialisation(const Point &startPoint, const Point &endPoint) {
  isNegative = endPoint.getX() - startPoint.getX() < 0;

  p = std::abs(endPoint.getX() - startPoint.getX());
}

void ParabolaDrawer::addPoints(std::vector<Point>& points, int x, int y, const Color & color) const {
  if (isNegative) {
    addPoint(points, Point(-x, -y));
    addPoint(points, Point(-x, y));
  } else {
    addPoint(points, Point(x, y));
    addPoint(points, Point(x, -y));
  }
}

int ParabolaDrawer::countVerticalError(int y, int error) const {
  return error + 2 * y + 1;
}

int ParabolaDrawer::countHorizontalError(int /*x*/, int error) const {
  return error - 2 * p;
}

int ParabolaDrawer::countDiagonalError(int /*x*/, int y, int error) const {
  return error + 2 * y + 1 - 2 * p;
}

int ParabolaDrawer::countStartError() const {
 return - 2 * p + 1;
}

int ParabolaDrawer::getStartX() const {
  return p / 2;
}

int ParabolaDrawer::getStartY() const {
  return 0;
}

bool ParabolaDrawer::isDiagonalOrHorizontal(int error) const {
  return error > 0;
}
  
bool ParabolaDrawer::isDiagonalOrVertical(int error) const {
  return error < 0;
}