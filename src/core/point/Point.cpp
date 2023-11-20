#include "Point.hpp"

Color::Color() : Color(BLACK) {}

Color::Color(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}

Point::Point(int x, int y) : x(x), y(y), z(0) {}

Point::Point(int x, int y, Color color) : x(x), y(y), z(0), color(color) {}

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

Point::Point(int x, int y, int z, Color color) : x(x), y(y), z(z), color(color) {}

Point& Point::toScreenPoint(const Point &zeroPoint) {
  x += zeroPoint.x;
  y = zeroPoint.y - y;
  return *this;
}

Point Point::operator-(const Point & rhs) const {
  return {x - rhs.x, y - rhs.y};
}

Point Point::operator+(const Point & rhs) const {
  return {x + rhs.x, y + rhs.y};
}


int Point::getX() const {
  return x;
}

int Point::getY() const {
  return y;
}

Color Point::getColor() const {
  return color;
}

