#include "LineDDAMode.hpp"
#include <cmath>

int round(float n)
{
    return static_cast<int>(n + 0.5f);
}

std::vector<Point> LineDDAMode::getLine(Point startPoint, Point endPoint) {
  std::vector<Point > line;
  
  int dx = endPoint.x - startPoint.x;
  int dy = endPoint.y - startPoint.y;

  int step;

  if (abs(dx) > abs(dy))
    step = abs(dx);
  else
    step = abs(dy);

  float x_incr = (float)dx / step;
  float y_incr = (float)dy / step;

  float x = startPoint.x;
  float y = startPoint.y;

  for (int i = 0; i < step; i++) {
    line.emplace_back(round(x), round(y));
    x += x_incr;
    y += y_incr;
  }

  return line;
}