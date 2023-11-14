#include "EllipseDrawer.hpp"
#include <algorithm>
#include <cmath>

void EllipseDrawer::initialisation(const Point &startPoint, const Point &endPoint) {
  a = std::abs(endPoint.getX() - startPoint.getX());
  b = std::abs(endPoint.getY() - startPoint.getY());
}

int EllipseDrawer::countVerticalError(int y, int error) const {
  return error + std::pow(a, 2) * (-2 * y + 1);
}

int EllipseDrawer::countHorizontalError(int x, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1);
}

int EllipseDrawer::countDiagonalError(int x, int y, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1) + std::pow(a, 2) * (-2 * y + 1);
}

int EllipseDrawer::countStartError() const {
  return std::pow(a, 2) + std::pow(b, 2) + 2 * std::pow(a, 2) * b;
}

int EllipseDrawer::getStartX() const {
  return 0;
}

int EllipseDrawer::getStartY() const {
  return b;
}

int EllipseDrawer::deltaY() const {
  return -1;
}

bool EllipseDrawer::stopCondition(int /*x*/, int y, int /*limitX*/, int /*limitY*/) const {
  return y <= 0;
}
