#include "Point.hpp"

Color::Color() : Color(BLACK) {}

Color::Color(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point::Point(int x, int y, Color color) : x(x), y(y), color(color) {}

Point& Point::toScreenPoint(const Point &zeroPoint) {
  x += zeroPoint.x;
  y = zeroPoint.y - y;
  return *this;
}
