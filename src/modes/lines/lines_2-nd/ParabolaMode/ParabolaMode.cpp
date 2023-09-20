#include "ParabolaMode.hpp"
#include <algorithm>
#include <cmath>

std::vector<Point> ParabolaMode::getLine(Point startPoint, Point endPoint) {
  zeroPoint = startPoint;

  isNegative = endPoint.x - startPoint.x < 0;

  p = std::abs(endPoint.x - startPoint.x);

  std::vector<Point> points;

  int x = p / 2;
  int y = 0;
  int limitX = 4000;
  int limitY = 4000;

  int error = countStartError();
  
  while (x < limitX && y < limitY) {
    addPoints(points, x, y);

    if (error > 0) {
      if (int delta = std::abs(countHorizontalError(x, error)) - std::abs(countDiagonalError(x, y, error)); delta > 0) {
        moveDiagonal(x, y, error);
      } else {
        moveHorizontal(x, error);
      }
      continue;
    }
    if (error < 0) {
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

void ParabolaMode::addPoint(std::vector<Point>& points, const Point &point) const {
  if (point.x < 0 || point.y < 0) return;
  points.emplace_back(point);
}

void ParabolaMode::moveDiagonal(int &x, int &y, int &error) const {
  error = countDiagonalError(x, y, error);
  x += 1;
  y += 1;
}

void ParabolaMode::moveVertical(int &y, int &error) const {
  error = countVerticalError(y, error);
  y += 1;
}
  
void ParabolaMode::moveHorizontal(int & x, int &error) const {
  error = countHorizontalError(x, error);
  x += 1;
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

