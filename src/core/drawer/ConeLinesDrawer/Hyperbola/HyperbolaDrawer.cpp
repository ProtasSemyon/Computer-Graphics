#include "HyperbolaDrawer.hpp"
#include <algorithm>
#include <cmath>

void HyperbolaDrawer::initialisation(const Point &startPoint, const Point &endPoint) {
  a = std::abs(endPoint.getX() - startPoint.getX());
  b = std::abs(endPoint.getY() - startPoint.getY());
}

int HorizontalHyperbolaDrawer::countDiagonalError(int x, int y, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1) - std::pow(a, 2) * (2 * y + 1);
}

int HorizontalHyperbolaDrawer::countVerticalError(int y, int error) const {
  return error - std::pow(a, 2) * (2 * y + 1);
}

int HorizontalHyperbolaDrawer::countHorizontalError(int x, int error) const {
  return error + std::pow(b, 2) * (2 * x + 1);
}

int HorizontalHyperbolaDrawer::countStartError() const {
  return -std::pow(a, 2) + std::pow(b, 2) + 2 * a * std::pow(b, 2);
}

int HorizontalHyperbolaDrawer::getStartX() const {
  return a;
}

int HorizontalHyperbolaDrawer::getStartY() const {
  return 0;
}

int VerticalHyperbolaDrawer::countDiagonalError(int x, int y, int error) const {
  return error - std::pow(b, 2) * (2 * x + 1) + std::pow(a, 2) * (2 * y + 1);
}

int VerticalHyperbolaDrawer::countVerticalError(int y, int error) const {
  return error + std::pow(a, 2) * (2 * y + 1);
}

int VerticalHyperbolaDrawer::countHorizontalError(int x, int error) const {
  return error - std::pow(b, 2) * (2 * x + 1);
}

int VerticalHyperbolaDrawer::countStartError() const {
  return std::pow(a, 2) - std::pow(b, 2) + 2 * b * std::pow(a, 2);
}

int VerticalHyperbolaDrawer::getStartX() const {
  return 0;
}

int VerticalHyperbolaDrawer::getStartY() const {
  return b;
}

bool VerticalHyperbolaDrawer::isDiagonalOrHorizontal(int error) const {
  return error > 0;
}

bool VerticalHyperbolaDrawer::isDiagonalOrVertical(int error) const {
  return error < 0;
}

