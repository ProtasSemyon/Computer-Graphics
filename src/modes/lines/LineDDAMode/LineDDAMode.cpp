#include "LineDDAMode.hpp"
#include <cmath>

int round(float n)
{
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

std::vector<Point> LineDDAMode::getLine(Point startPoint, Point endPoint) {
  std::vector<Point > line;
  // Calculate dx and dy
  int dx = endPoint.x - startPoint.x;
  int dy = endPoint.y - startPoint.y;

  int step;

  // If dx > dy we will take step as dx
  // else we will take step as dy to draw the complete
  // line
  if (abs(dx) > abs(dy))
    step = abs(dx);
  else
    step = abs(dy);

  // Calculate x-increment and y-increment for each step
  float x_incr = (float)dx / step;
  float y_incr = (float)dy / step;

  // Take the initial points as x and y
  float x = startPoint.x;
  float y = startPoint.y;

  for (int i = 0; i < step; i++) {
    line.emplace_back(round(x), round(y));
    x += x_incr;
    y += y_incr;
    // delay(10);
  }

  return line;
}