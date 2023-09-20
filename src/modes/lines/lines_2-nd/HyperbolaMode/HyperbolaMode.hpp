#pragma once

#include "modes/lines/ILineMode.hpp"


class HyperbolaMode : public ILineMode {

protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;

  int a;
  int b;
private:
  Point zeroPoint;

  void addPoints(std::vector<Point>& points, int x, int y) const;

  void addPoint(std::vector<Point>& points, const Point & point) const;

  void moveDiagonal(int &x, int &y, int &error) const;

  void moveVertical(int &y, int &error) const;

  void moveHorizontal(int &x, int &error) const;

  virtual int countVerticalError(int y, int error) const = 0;

  virtual int countHorizontalError(int x, int error) const = 0;

  virtual int countDiagonalError(int x, int y, int error) const = 0;

  virtual int countStartError() const = 0;

  virtual int getStartX() const = 0;

  virtual int getStartY() const = 0;

  virtual bool isDiagonalOrHorizontal(int error) const = 0;
  
  virtual bool isDiagonalOrVertical(int error) const = 0;
};

class HorizontalHyperbolaMode : public HyperbolaMode {
private:
  int countVerticalError(int y, int error) const override;

  int countHorizontalError(int x, int error) const override;

  int countDiagonalError(int x, int y, int error) const override;

  int countStartError() const override;

  int getStartX() const override;

  int getStartY() const override;

  bool isDiagonalOrHorizontal(int error) const override;
  
  bool isDiagonalOrVertical(int error) const override;
};

class VerticalHyperbolaMode : public HyperbolaMode {
private:
  int countVerticalError(int y, int error) const override;

  int countHorizontalError(int x, int error) const override;

  int countDiagonalError(int x, int y, int error) const override;

  int countStartError() const override;

  int getStartX() const override;

  int getStartY() const override;

  bool isDiagonalOrHorizontal(int error) const override;
  
  bool isDiagonalOrVertical(int error) const override;
};