#pragma once

#include "modes/lines/ILineMode.hpp"

class CircleMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;
private:
  int radius;
  Point zeroPoint;

  static int findRadius(const Point &startPoint, const Point &endPoint);
  void addPoints(std::vector<Point>& points, int x, int y) const;

  void addPoint(std::vector<Point>& points, const Point & point) const;

  static void moveD(int &x, int &y, int &error);

  static void moveV(int &x, int &y, int &error);

  static void moveH(int &x, int &y, int &error);

};