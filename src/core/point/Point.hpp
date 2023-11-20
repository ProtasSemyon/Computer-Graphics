#pragma once

#include <vector>

struct Color {
  Color();
  Color(float red, float green, float blue, float alpha);

  float r;
  float g;
  float b;
  float a;
};

const Color BLACK(0.0f, 0.0f, 0.0f, 1.0f);
const Color WHITE(1.0f, 1.0f, 1.0f, 1.0f);
const Color RED(1.0f, 0.0f, 0.0f, 1.0f);
const Color GREEN(0.0f, 1.0f, 0.0f, 1.0f);
const Color BLUE(0.0f, 0.0f, 1.0f, 1.0f);


class Point {
public:
  Point() = default;

  Point(int x, int y);

  Point(int x, int y, Color color);

  Point(int x, int y, int z);

  Point(int x, int y, int z, Color color);

  int getX() const;

  int getY() const;

  Color getColor() const;

  Point& toScreenPoint(const Point &zeroPoint);

  Point operator-(const Point & rhs) const;

  Point operator+(const Point & rhs) const;

private:
  int x;

  int y;

  int z;
  
  Color color;
};

using PointVector = std::vector<Point>;
