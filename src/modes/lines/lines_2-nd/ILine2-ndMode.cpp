#include "ILine2-ndMode.hpp"
#include <algorithm>

std::vector<Point> ILine2_ndMode::getLine(Point startPoint, Point endPoint) {
  initialisation(startPoint, endPoint);

  zeroPoint = startPoint;

  std::vector<Point> points;

  int x = getStartX();
  int y = getStartY();
  int limitX = getLimitX(startPoint);
  int limitY = getLimitY(startPoint);

  int error = countStartError();
  
  while (!stopCondition(x, y, limitX, limitY)) {
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
      if (int delta = std::abs(countVerticalError(y, error)) - std::abs(countDiagonalError(x, y, error)); delta >= 0) {
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

int ILine2_ndMode::getLimitX(const Point &startPoint) const {
  return std::max(startPoint.x, window->getWidth() - startPoint.x);
}

int ILine2_ndMode::getLimitY(const Point &startPoint) const {
  return std::max(startPoint.y, window->getHeight() - startPoint.y);
}

bool ILine2_ndMode::isDiagonalOrHorizontal(int error) const {
  return error < 0;
}
  
bool ILine2_ndMode::isDiagonalOrVertical(int error) const {
  return error > 0;
}

void ILine2_ndMode::addPoint(std::vector<Point>& points, const Point &point) const {
  if (point.x < 0 || point.y < 0 || point.x > window->getWidth() || point.y > window->getHeight()) return;
  points.emplace_back(point);
}

void ILine2_ndMode::addPoints(std::vector<Point>& points, int x, int y) const {
  addPoint(points, Point(-x, -y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(x, -y).toScreenPoint(zeroPoint));
}

int ILine2_ndMode::deltaX() const {
  return 1;
}

int ILine2_ndMode::deltaY() const {
  return 1;
}

void ILine2_ndMode::moveDiagonal(int &x, int &y, int &error) const {
  error = countDiagonalError(x, y, error);
  x += deltaX();
  y += deltaY();
}

void ILine2_ndMode::moveVertical(int &y, int &error) const {
  error = countVerticalError(y, error);
  y += deltaY();
}
  
void ILine2_ndMode::moveHorizontal(int & x, int &error) const {
  error = countHorizontalError(x, error);
  x += deltaX();
}

bool ILine2_ndMode::stopCondition(int x, int y, int limitX, int limitY) const {
  return x > limitX || y > limitY;
}
