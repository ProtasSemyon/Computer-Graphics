#include "CircleDrawer.hpp"

#include <algorithm>
#include <cmath>

void CircleDrawer::initialisation(const Point &startPoint, const Point &endPoint) {
  radius = findRadius(startPoint, endPoint);
}

int CircleDrawer::getStartX() const {
  return 0;
}

int CircleDrawer::getStartY() const {
  return radius;
}

int CircleDrawer::countStartError() const {
  return 2 - 2 * radius;
}

int CircleDrawer::countVerticalError(int y, int error) const {
  return error - 2 * y + 1;
}

int CircleDrawer::countHorizontalError(int x, int error) const {
  return error + 2 * x + 1;
}

int CircleDrawer::countDiagonalError(int x, int y, int error) const {
  return error + 2 * x - 2 * y + 2;
}

int CircleDrawer::findRadius(const Point &startPoint, const Point &endPoint) {
  return static_cast<int>(std::sqrt(std::pow(startPoint.getX() - endPoint.getX(), 2) + std::pow(startPoint.getY() - endPoint.getY(), 2)) + 0.5);
}

int CircleDrawer::deltaY() const {
  return -1;
}

bool CircleDrawer::stopCondition(int /*x*/, int y, int /*limitX*/, int /*limitY*/) const {
  return y <= 0;
}



