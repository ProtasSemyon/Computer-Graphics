#include "Drawer.hpp"
#include "core/utils/Utils.hpp"
#include <cmath>
#include <iostream>

#include "core/drawer/ConeLinesDrawer/Circle/CircleDrawer.hpp"
#include "core/drawer/ConeLinesDrawer/Ellipse/EllipseDrawer.hpp"
#include "core/drawer/ConeLinesDrawer/Hyperbola/HyperbolaDrawer.hpp"
#include "core/drawer/ConeLinesDrawer/Parabola/ParabolaDrawer.hpp"

#include "core/drawer/CurveDrawer/BSplineDrawer/BSplineDrawer.hpp"
#include "core/drawer/CurveDrawer/BesieCurveDrawer/BesieCurveDrawer.hpp"
#include "core/drawer/CurveDrawer/HermitCurveDrawer/HermitCurveDrawer.hpp"

//Lines start
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
  color.r = (brightness);
  color.g = (brightness);
  color.b = (brightness);

  if (inverted) {
    points.emplace_back(y, x, color);
  } else {
    points.emplace_back(x, y, color);
  }
}

//Lines end

//ConeLines start
PointVector Drawer::getCircle(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static CircleDrawer circleDrawer;
  circleDrawer.setMaxX(maxPoint.getX());
  circleDrawer.setMaxY(maxPoint.getY());
  return circleDrawer.getPoints(startPoint, endPoint, color);
}

PointVector Drawer::getEllipse(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static EllipseDrawer ellipseDrawer;
  ellipseDrawer.setMaxX(maxPoint.getX());
  ellipseDrawer.setMaxY(maxPoint.getY());
  return ellipseDrawer.getPoints(startPoint, endPoint, color);
}

PointVector Drawer::getHyperbola(const Point& startPoint, const Point& endPoint, const Point& maxPoint, bool isHorizontal, const Color& color) {
  if(isHorizontal) {
    static HorizontalHyperbolaDrawer horizontalHyperbolaDrawer;
    horizontalHyperbolaDrawer.setMaxX(maxPoint.getX());
    horizontalHyperbolaDrawer.setMaxY(maxPoint.getY());
    return horizontalHyperbolaDrawer.getPoints(startPoint, endPoint, color);
  }
  static VerticalHyperbolaDrawer verticalHyperbolaDrawer;
  verticalHyperbolaDrawer.setMaxX(maxPoint.getX());
  verticalHyperbolaDrawer.setMaxY(maxPoint.getY());
  return verticalHyperbolaDrawer.getPoints(startPoint, endPoint, color);
}

PointVector Drawer::getParabola(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static ParabolaDrawer parabolaDrawer;
  parabolaDrawer.setMaxX(maxPoint.getX());
  parabolaDrawer.setMaxY(maxPoint.getY());
  return parabolaDrawer.getPoints(startPoint, endPoint, color);
}
//ConeLines end

//Curve start
PointVector Drawer::getHermitCurve(const PointVector& controlPoints, const Color& color) {
  static HermitCurveDrawer hermitCurveDrawer;
  return hermitCurveDrawer.getPoints(controlPoints, color);
}

PointVector Drawer::getBesieCurve(const PointVector& controlPoints, const Color& color) {
  static BesieCurveDrawer besieCurveDrawer;
  return besieCurveDrawer.getPoints(controlPoints, color);
}

PointVector Drawer::getBSplineCurve(const PointVector& controlPoints, bool isClosed, const Color& color) {
  static BSplineDrawer bsplineDrawer;
  return bsplineDrawer.getPoints(controlPoints, color, isClosed);
}
//Curve end

