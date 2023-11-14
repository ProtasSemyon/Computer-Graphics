#include "Drawer.hpp"
#include "core/utils/Utils.hpp"
#include <cmath>


PointVector getVerticalLine(Point startPoint, Point endPoint, Color color);

PointVector getHorizontalLine(Point startPoint, Point endPoint, Color color);

PointVector getDiagonalLine(Point startPoint, Point endPoint, Color color);

void addPoint(PointVector &points, int x, int y, Color color, bool inverted, float brightness);

PointVector Drawer::getDDALine(const Point& startPoint, const Point& endPoint, const Color& color){
  std::vector<Point > line;
  
  int dx = endPoint.getX() - startPoint.getX();
  int dy = endPoint.getY() - startPoint.getY();

  int step;

  if (abs(dx) > abs(dy))
    step = abs(dx);
  else
    step = abs(dy);

  float x_incr = (float)dx / step;
  float y_incr = (float)dy / step;

  float x = startPoint.getX();
  float y = startPoint.getY();

  for (int i = 0; i < step; i++) {
    line.emplace_back(round(x), round(y), color);
    x += x_incr;
    y += y_incr;
  }

  return line;
}

PointVector Drawer::getBresenhemLine(const Point& startPoint, const Point& endPoint, const Color& color){
  int x1 = startPoint.getX();
  int x2 = endPoint.getX();
  int y1 = startPoint.getY();
  int y2 = endPoint.getY();
  PointVector line;

  const int deltaX = std::abs(x2 - x1);
  const int deltaY = std::abs(y2 - y1);
  const int signX = x1 < x2 ? 1 : -1;
  const int signY = y1 < y2 ? 1 : -1;
  int error = deltaX - deltaY;
  line.emplace_back(x2, y2, color);

  while(x1 != x2 || y1 != y2) 
  {
    line.emplace_back(x1, y1, color);
    int error2 = error * 2;
    if(error2 > -deltaY) 
    {
      error -= deltaY;
      x1 += signX;
    } 
    if(error2 < deltaX) 
    {
      error += deltaX;
      y1 += signY;
    }
  }

  return line;
}

PointVector Drawer::getWuLine(const Point& startPoint, const Point& endPoint, const Color& color){
  std::vector<Point> line;

  float x1 = startPoint.getX();
  float x2 = endPoint.getX();
  float y1 = startPoint.getY();
  float y2 = endPoint.getY();

  if (x1 == x2) {
    return getVerticalLine(startPoint, endPoint, color);
  }

  if (y1 == y2) {
    return getHorizontalLine(startPoint, endPoint, color);
  }

  if (std::abs(x1 - x2) == std::abs(y1 - y2)) {
    return getDiagonalLine(startPoint, endPoint, color);
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

  addPoint(line, xpxl1, ypxl1, color, inverted, fpart(yend) * xgap);

  float intery = yend + grad;

  xend = round(x2);
  yend = y2 + grad * (xend - x2);
  xgap = fpart(x2 + 0.5);

  int xpxl2 = xend;
  int ypxl2 = ipart(yend);

  addPoint(line, xpxl2, ypxl2, color, inverted, fpart(yend) * xgap);

  for (int x = xpxl1 + 1; x < xpxl2; x++) {
    addPoint(line, x, ipart(intery), color, inverted, fpart(intery));
    addPoint(line, x, ipart(intery) + 1, color, inverted, 1 - fpart(intery));
    intery += grad;
  }
  return line;
}

PointVector getVerticalLine(Point startPoint, Point endPoint, Color color) {
  PointVector line;
  line.emplace_back(startPoint);
  int signY = endPoint.getY() - startPoint.getY() > 0 ? 1 : -1;

  int x = startPoint.getX();
  int y = startPoint.getY();
  while(y != endPoint.getY()) {
    y += signY;
    line.emplace_back(x, y, color);
  }

  return line;
}

PointVector getHorizontalLine(Point startPoint, Point endPoint, Color color) {
  PointVector line;
  line.emplace_back(startPoint);
  int signX = endPoint.getX() - startPoint.getX() > 0 ? 1 : -1;
  int x = startPoint.getX();
  int y = startPoint.getY();
  while(x != endPoint.getX()) {
    x += signX;
    line.emplace_back(x, y, color);
  }

  return line;
}

PointVector getDiagonalLine(Point startPoint, Point endPoint, Color color) {
  PointVector line;
  line.emplace_back(startPoint);
  int signX = endPoint.getX() - startPoint.getX() > 0 ? 1 : -1;
  int signY = endPoint.getY() - startPoint.getY() > 0 ? 1 : -1;

  int x = startPoint.getX();
  int y = startPoint.getY();

  while(x != endPoint.getX() && y != endPoint.getY()) {
    y += signY;
    x += signX;
    line.emplace_back(x, y, color);
  }

  return line;
}

void addPoint(PointVector &points, int x, int y, Color color, bool inverted, float brightness) {
  color.r += (1 - color.r) * (1 - brightness);
  color.g += (1 - color.g) * (1 - brightness);
  color.b += (1 - color.b) * (1 - brightness);

  if (inverted) {
    points.emplace_back(y, x, color);
  } else {
    points.emplace_back(x, y, color);
  }
}