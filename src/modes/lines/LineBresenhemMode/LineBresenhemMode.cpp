#include <cmath>

#include "LineBresenhemMode.hpp"

std::vector<Point> LineBresenhemMode::getLine(Point startPoint, Point endPoint) {
  int x1 = startPoint.x;
  int x2 = endPoint.x;
  int y1 = startPoint.y;
  int y2 = endPoint.y;
  std::vector<Point > line;

  const int deltaX = abs(x2 - x1);
  const int deltaY = abs(y2 - y1);
  const int signX = x1 < x2 ? 1 : -1;
  const int signY = y1 < y2 ? 1 : -1;
  int error = deltaX - deltaY;
  line.emplace_back(x2, y2);

  while(x1 != x2 || y1 != y2) 
  {
    line.emplace_back(x1, y1);
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
