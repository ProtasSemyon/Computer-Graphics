#include "LineDDAMode.hpp"
#include <cmath>

int round(float n)
{
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

std::vector<std::pair<int, int> > LineDDAMode::getLine(std::pair<int, int> startPoint, std::pair<int, int> endPoint) {
  std::vector<std::pair<int, int> > line;
  // Calculate dx and dy
  int dx = endPoint.first - startPoint.first;
  int dy = endPoint.second - startPoint.second;

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
  float x = startPoint.first;
  float y = startPoint.second;

  for (int i = 0; i < step; i++) {
    line.emplace_back(std::make_pair(round(x), round(y)));
    x += x_incr;
    y += y_incr;
    // delay(10);
  }

  return line;
}