#include "LineWuMode.hpp"
#include <cmath>

int ipart(float x) {
  return static_cast<int>(x);
}

float fpart(float x) {
  return x - ipart(x);
}

std::vector<Point> LineWuMode::getLine(Point startPoint, Point endPoint) {
  std::vector<Point> line;

  float x1 = startPoint.x;
  float x2 = endPoint.x;
  float y1 = startPoint.y;
  float y2 = endPoint.y;

  if (x1 == x2) {
    return getVerticalLine(startPoint, endPoint);
  }

  if (y1 == y2) {
    return getHorizontalLine(startPoint, endPoint);
  }

  if (std::abs(x1 - x2) == std::abs(y1 - y2)) {
    return getDiagonalLine(startPoint, endPoint);
  }

  bool inverted = false;

  if (std::abs(x1 - x2) < std::abs(y1 - y2)) {
    inverted = true;
    std::swap(x1, y1);
    std::swap(x2, y2);
  }

  if (x2 < x1) {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }

  float dx = x2 - x1;
  float dy = y2 - y1;
  float grad = dy / dx;

  int xend = round(x1);
  int yend = y1 + grad * (xend - x1);
  float xgap = 1 - fpart(x1 + 0.5);

  int xpxl1 = xend;
  int ypxl1 = ipart(yend);

  addPoint(line, xpxl1, ypxl1, fpart(yend) * xgap, inverted);

  float intery = yend + grad;

  xend = round(x2);
  yend = y2 + grad * (xend - x2);
  xgap = fpart(x2 + 0.5);

  int xpxl2 = xend;
  int ypxl2 = ipart(yend);

  addPoint(line, xpxl2, ypxl2, fpart(yend) * xgap, inverted);

  for (int x = xpxl1 + 1; x < xpxl2; x++) {
    addPoint(line, x, ipart(intery), fpart(intery), inverted);
    addPoint(line, x, ipart(intery) + 1, 1 - fpart(intery), inverted);
    intery += grad;
  }
  return line;
}

void LineWuMode::addPoint(std::vector<Point> &points, int x, int y, float color, bool inverted) const {
  if (inverted) {
    points.emplace_back(y, x, Color(color, color, color, 1.0f));
  } else {
    points.emplace_back(x, y, Color(color, color, color, 1.0f));
  }
}

std::vector<Point> LineWuMode::getVerticalLine(Point startPoint, Point endPoint) const {
  std::vector<Point> line;
  line.emplace_back(startPoint);
  int signY = endPoint.y - startPoint.y > 0 ? 1 : -1;
  while(startPoint.y != endPoint.y) {
    startPoint.y += signY;
    line.emplace_back(startPoint);
  }

  return line;
}

std::vector<Point> LineWuMode::getHorizontalLine(Point startPoint, Point endPoint) const {
  std::vector<Point> line;
  line.emplace_back(startPoint);
  int signX = endPoint.x - startPoint.x > 0 ? 1 : -1;
  while(startPoint.x != endPoint.x) {
    startPoint.x += signX;
    line.emplace_back(startPoint);
  }

  return line;
}

std::vector<Point> LineWuMode::getDiagonalLine(Point startPoint, Point endPoint) const {
  std::vector<Point> line;
  line.emplace_back(startPoint);
  int signX = endPoint.x - startPoint.x > 0 ? 1 : -1;
  int signY = endPoint.y - startPoint.y > 0 ? 1 : -1;

  while(startPoint.x != endPoint.x && startPoint.y != endPoint.y) {
    startPoint.y += signY;
    startPoint.x += signX;
    line.emplace_back(startPoint);
  }

  return line;
}

