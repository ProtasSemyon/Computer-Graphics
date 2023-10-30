#pragma once
#include "core/point/Point.hpp"

const int DEFAULT_RADIUS = 10;

class RefPoint {
public:
  RefPoint(int x, int y, int r = DEFAULT_RADIUS);

  void draw() const;

  operator Point() const;

private:
  int x;
  int y;
  int r;
};