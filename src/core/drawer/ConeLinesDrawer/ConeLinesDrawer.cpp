#include "ConeLinesDrawer.hpp"
#include <algorithm>

PointVector ConeLinesDrawer::getPoints(Point startPoint, Point endPoint, const Color &color) {
  initialisation(startPoint, endPoint);

  PointVector points;

  int x = getStartX();
  int y = getStartY();
  int limitX = getLimitX(startPoint);
  int limitY = getLimitY(startPoint);

  int error = countStartError();
  
  while (!stopCondition(x, y, limitX, limitY)) {
    addPoints(points, x, y, color);

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
  addPoints(points, x, y, color);

  return points;
}

int ConeLinesDrawer::getLimitX(const Point &startPoint) const {
  return std::max(startPoint.getX(), maxX - startPoint.getX());
}

int ConeLinesDrawer::getLimitY(const Point &startPoint) const {
  return std::max(startPoint.getY(), maxY - startPoint.getY());
}

bool ConeLinesDrawer::isDiagonalOrHorizontal(int error) const {
  return error < 0;
}
  
bool ConeLinesDrawer::isDiagonalOrVertical(int error) const {
  return error > 0;
}

void ConeLinesDrawer::addPoint(std::vector<Point>& points, const Point &point) const {
  if (point.getX() < 0 || point.getY() < 0 || point.getX() > maxX || point.getY() > maxY) return;
  points.emplace_back(point);
}

void ConeLinesDrawer::addPoints(std::vector<Point>& points, int x, int y, const Color &color) const {
  addPoint(points, Point(-x, -y, color));
  addPoint(points, Point(-x, y, color));
  addPoint(points, Point(x, y, color));
  addPoint(points, Point(x, -y, color));
}

int ConeLinesDrawer::deltaX() const {
  return 1;
}

int ConeLinesDrawer::deltaY() const {
  return 1;
}

void ConeLinesDrawer::moveDiagonal(int &x, int &y, int &error) const {
  error = countDiagonalError(x, y, error);
  x += deltaX();
  y += deltaY();
}

void ConeLinesDrawer::moveVertical(int &y, int &error) const {
  error = countVerticalError(y, error);
  y += deltaY();
}
  
void ConeLinesDrawer::moveHorizontal(int & x, int &error) const {
  error = countHorizontalError(x, error);
  x += deltaX();
}

bool ConeLinesDrawer::stopCondition(int x, int y, int limitX, int limitY) const {
  return x > limitX || y > limitY;
}

void ConeLinesDrawer::setMaxX(int x) {
  maxX = x;
}

void ConeLinesDrawer::setMaxY(int y) {
  maxY = y;
}
