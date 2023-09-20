#include "EllipseMode.hpp"
#include <algorithm>
#include <cmath>

void EllipseMode::initialisation(const Point &startPoint, const Point &endPoint) {
  a = std::abs(endPoint.x - startPoint.x);
  b = std::abs(endPoint.y - startPoint.y);
}

int EllipseMode::countVerticalError(int y, int error) const {
  return error + std::pow(a, 2) * (-2 * y + 1);
}

int EllipseMode::countHorizontalError(int x, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1);
}

int EllipseMode::countDiagonalError(int x, int y, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1) + std::pow(a, 2) * (-2 * y + 1);
}

int EllipseMode::countStartError() const {
  return std::pow(a, 2) + std::pow(b, 2) + 2 * std::pow(a, 2) * b;
}

int EllipseMode::getStartX() const {
  return 0;
}

int EllipseMode::getStartY() const {
  return b;
}

int EllipseMode::deltaY() const {
  return -1;
}

bool EllipseMode::stopCondition(int /*x*/, int y, int /*limitX*/, int /*limitY*/) const {
  return y <= 0;
}



