#pragma once

#include "modes/lines/ILineMode.hpp"

class EllipseMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;
private:
  Point zeroPoint;

  int a;

  int b;

  void addPoints(std::vector<Point>& points, int x, int y) const;

  void addPoint(std::vector<Point>& points, const Point & point) const;

  void moveD(int &x, int &y, int &error) const;

  void moveV(int &x, int &y, int &error) const;

  void moveH(int &x, int &y, int &error) const;

};