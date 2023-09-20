#include "HyperbolaMode.hpp"
#include <algorithm>
#include <cmath>

std::vector<Point> HyperbolaMode::getLine(Point startPoint, Point endPoint) {
  zeroPoint = startPoint;

  a = std::abs(endPoint.x - startPoint.x);
  b = std::abs(endPoint.y - startPoint.y);

  std::vector<Point> points;

  int x = getStartX();
  int y = getStartY();
  int limitX = 4000;
  int limitY = 4000;

  int error = countStartError();
  
  while (x < limitX && y < limitY) {
    addPoints(points, x, y);

    if (isDiagonalOrHorizontal(error)) {
      if (int delta = std::abs(countHorizontalError(x, error)) - std::abs(countDiagonalError(x, y, error)); delta > 0) {
        moveDiagonal(x, y, error);
      } else {
        moveHorizontal(x, error);
      }
      continue;
    }
    if (isDiagonalOrVertical(error)) {
      if (int delta = std::abs(countVerticalError(y, error)) - std::abs(countDiagonalError(x, y, error)); delta > 0) {
        moveDiagonal(x, y, error);
      } else {
        moveVertical(y, error);
      }
      continue;
    }
    if (error == 0) {
      moveDiagonal(x, y, error);
      continue;
    }
  }
  addPoints(points, x, y);

  return points;
}

void HyperbolaMode::addPoint(std::vector<Point>& points, const Point &point) const {
  if (point.x < 0 || point.y < 0) return;
  points.emplace_back(point);
}

void HyperbolaMode::moveDiagonal(int &x, int &y, int &error) const {
  error = countDiagonalError(x, y, error); 
  x += 1;
  y += 1;
}

void HyperbolaMode::moveVertical(int &y, int &error) const {
  error = countVerticalError(y, error);
  y += 1;
}
  
void HyperbolaMode::moveHorizontal(int &x, int &error) const {
  error = countHorizontalError(x, error);
  x += 1;
}

void HyperbolaMode::addPoints(std::vector<Point>& points, int x, int y) const {
  addPoint(points, Point(x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(x, -y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, -y).toScreenPoint(zeroPoint));

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

bool HorizontalHyperbolaMode::isDiagonalOrHorizontal(int error) const {
  return error < 0;
}

bool HorizontalHyperbolaMode::isDiagonalOrVertical(int error) const {
  return error > 0;
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

