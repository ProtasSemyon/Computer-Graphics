#pragma once

#include "modes/lines/ILineMode.hpp"

class ParabolaMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;
private:
  Point zeroPoint;

  int p;

  void addPoints(std::vector<Point>& points, int x, int y) const;

  void addPoint(std::vector<Point>& points, const Point & point) const;

  void moveDiagonal(int &x, int &y, int &error) const;

  void moveVertical(int &y, int &error) const;

  void moveHorizontal(int &x, int &error) const;

  int countVerticalError(int y, int error) const;

  int countHorizontalError(int x, int error) const;

  int countDiagonalError(int x, int y, int error) const;

  int countStartError() const;

  bool isNegative = false;

};