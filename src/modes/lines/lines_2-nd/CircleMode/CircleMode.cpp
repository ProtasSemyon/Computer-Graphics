#include "CircleMode.hpp"
#include <algorithm>
#include <cmath>

std::vector<Point> CircleMode::getLine(Point startPoint, Point endPoint) {
  zeroPoint = startPoint;
  radius = findRadius(startPoint, endPoint);

  std::vector<Point> points;

  int x = 0;
  int y = radius;
  int limit = 0;

  int error = 2 - 2 * radius;
  
  while (y > limit) {
    addPoints(points, x, y);

    if (error < 0) {
      if (int delta = 2 * error + 2 * y - 1; delta > 0) {
        moveD(x, y, error);
      } else {
        moveH(x, y, error);
      }
      continue;
    }
    if (error > 0) {
      if (int delta = 2 * error - 2 * x - 1; delta > 0) {
        moveV(x, y, error);
      } else {
        moveD(x, y, error);
      }
      continue;
    }
    if (error == 0) {
      moveD(x, y, error);
      continue;
    }
  }
  addPoints(points, x, y);


  return points;
}

int CircleMode::findRadius(const Point &startPoint, const Point &endPoint) {
  return static_cast<int>(std::sqrt(std::pow(startPoint.x - endPoint.x, 2) + std::pow(startPoint.y - endPoint.y, 2)) + 0.5);
}

void CircleMode::addPoint(std::vector<Point>& points, const Point &point) const {
  if (point.x < 0 || point.y < 0) return;
  points.emplace_back(point);
}

void CircleMode::moveD(int &x, int &y, int &error) {
  x += 1;
  y -= 1;
  error += 2 * x - 2 * y + 2;
}

void CircleMode::moveV(int &/*x*/, int &y, int &error) {
  y -= 1;
  error += -2 * y + 1;
}
  
void CircleMode::moveH(int &x, int &/*y*/, int &error) {
  x += 1;
  error += 2 * x + 1;
}

void CircleMode::addPoints(std::vector<Point>& points, int x, int y) const {
  addPoint(points, Point(x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(x, -y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, -y).toScreenPoint(zeroPoint));

}

