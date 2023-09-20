#include "EllipseMode.hpp"
#include <algorithm>
#include <cmath>

std::vector<Point> EllipseMode::getLine(Point startPoint, Point endPoint) {
  zeroPoint = startPoint;

  a = std::abs(endPoint.x - startPoint.x);
  b = std::abs(endPoint.y - startPoint.y);

  std::vector<Point> points;

  int x = 0;
  int y = b;
  int limit = 0;

  int error = std::pow(a, 2) + std::pow(b, 2) + 2 * std::pow(a, 2) * b;

  auto countDError = [this](int xpxl, int ypxl, int currError){
    return currError + std::pow(b, 2) * (2 * xpxl + 1) + std::pow(a, 2) * (-2 * ypxl + 1);
  };
  
  while (y > limit) {
    addPoints(points, x, y);

    if (error < 0) {
      if (int delta = 2 * (countDError(x, y, error) + std::pow(a, 2) * y) - 1; delta > 0) {
        moveD(x, y, error);
      } else {
        moveH(x, y, error);
      }
      continue;
    }
    if (error > 0) {
      if (int delta = 2 * (countDError(x, y, error) - std::pow(b, 2) * x) - 1; delta > 0) {
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

void EllipseMode::addPoint(std::vector<Point>& points, const Point &point) const {
  if (point.x < 0 || point.y < 0) return;
  points.emplace_back(point);
}

void EllipseMode::moveD(int &x, int &y, int &error) const {
  error += std::pow(b, 2) * (2 * x + 1) + std::pow(a, 2) * (-2 * y + 1);
  x += 1;
  y -= 1;
}

void EllipseMode::moveV(int &/*x*/, int &y, int &error) const {
  error += std::pow(a, 2) * (-2 * y + 1);
  y -= 1;
}
  
void EllipseMode::moveH(int &x, int &/*y*/, int &error) const {
  error += std::pow(b, 2) * (2 * x + 1);
  x += 1;
}

void EllipseMode::addPoints(std::vector<Point>& points, int x, int y) const {
  addPoint(points, Point(x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, y).toScreenPoint(zeroPoint));
  addPoint(points, Point(x, -y).toScreenPoint(zeroPoint));
  addPoint(points, Point(-x, -y).toScreenPoint(zeroPoint));

}

