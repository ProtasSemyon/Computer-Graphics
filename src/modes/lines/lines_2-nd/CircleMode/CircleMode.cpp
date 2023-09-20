#include "CircleMode.hpp"
#include <algorithm>
#include <cmath>

void CircleMode::initialisation(const Point &startPoint, const Point &endPoint) {
  radius = findRadius(startPoint, endPoint);
}

int CircleMode::getStartX() const {
  return 0;
}

int CircleMode::getStartY() const {
  return radius;
}

int CircleMode::countStartError() const {
  return 2 - 2 * radius;
}

int CircleMode::countVerticalError(int y, int error) const {
  return error - 2 * y + 1;
}

int CircleMode::countHorizontalError(int x, int error) const {
  return error + 2 * x + 1;
}

int CircleMode::countDiagonalError(int x, int y, int error) const {
  return error + 2 * x - 2 * y + 2;
}

int CircleMode::findRadius(const Point &startPoint, const Point &endPoint) {
  return static_cast<int>(std::sqrt(std::pow(startPoint.x - endPoint.x, 2) + std::pow(startPoint.y - endPoint.y, 2)) + 0.5);
}

int CircleMode::deltaY() const {
  return -1;
}

bool CircleMode::stopCondition(int x, int y, int limitX, int limitY) const {
  return y <= 0;
}



