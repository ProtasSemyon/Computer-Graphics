#include "HyperbolaMode.hpp"
#include <algorithm>
#include <cmath>

void HyperbolaMode::initialisation(const Point &startPoint, const Point &endPoint) {
  a = std::abs(endPoint.x - startPoint.x);
  b = std::abs(endPoint.y - startPoint.y);
}

int HorizontalHyperbolaMode::countDiagonalError(int x, int y, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1) - std::pow(a, 2) * (2 * y + 1);
}

int HorizontalHyperbolaMode::countVerticalError(int y, int error) const {
  return error - std::pow(a, 2) * (2 * y + 1);
}

int HorizontalHyperbolaMode::countHorizontalError(int x, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1);
}

int HorizontalHyperbolaMode::countStartError() const {
  return -std::pow(a, 2) + std::pow(b, 2) + 2 * a * std::pow(b, 2);
}

int HorizontalHyperbolaMode::getStartX() const {
  return a;
}

int HorizontalHyperbolaMode::getStartY() const {
  return 0;
}

int VerticalHyperbolaMode::countDiagonalError(int x, int y, int error) const {
  return error - std::pow(b, 2) * (2 * x + 1) + std::pow(a, 2) * (2 * y + 1);
}

int VerticalHyperbolaMode::countVerticalError(int y, int error) const {
  return error + std::pow(a, 2) * (2 * y + 1);
}

int VerticalHyperbolaMode::countHorizontalError(int x, int error) const {
  return error - std::pow(b, 2) * (2 * x + 1);
}

int VerticalHyperbolaMode::countStartError() const {
  return std::pow(a, 2) - std::pow(b, 2) + 2 * b * std::pow(a, 2);
}

int VerticalHyperbolaMode::getStartX() const {
  return 0;
}

int VerticalHyperbolaMode::getStartY() const {
  return b;
}

bool VerticalHyperbolaMode::isDiagonalOrHorizontal(int error) const {
  return error > 0;
}

bool VerticalHyperbolaMode::isDiagonalOrVertical(int error) const {
  return error < 0;
}

