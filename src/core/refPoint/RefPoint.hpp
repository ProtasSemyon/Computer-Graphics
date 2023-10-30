#pragma once
#include "core/point/Point.hpp"

const int DEFAULT_RADIUS = 10;

class RefPoint {
public:
  RefPoint(int x, int y, int r = DEFAULT_RADIUS);

  void setPosition(int x, int y);

  void draw() const;

  bool isPressed(const Point &pressPoint) const;

  operator Point() const;

private:
  int x;
  int y;
  int r;
};