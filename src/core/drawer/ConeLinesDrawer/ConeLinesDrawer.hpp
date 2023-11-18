#pragma once

#include "core/point/Point.hpp"

class ConeLinesDrawer {
public:
  PointVector getPoints(Point startPoint, Point endPoint, const Color & color);

  void setMaxX(int x);

  void setMaxY(int y);

  virtual ~ConeLinesDrawer() = default;

protected:
  virtual void addPoint(PointVector& points, const Point & point) const;

private:

  int getLimitX(const Point &startPoint) const;

  int getLimitY(const Point &startPoint) const;

  void moveDiagonal(int &x, int &y, int &error) const;

  void moveVertical(int &y, int &error) const;

  void moveHorizontal(int &x, int &error) const;

  virtual void initialisation(const Point &startPoint, const Point &endPoint) = 0;

  virtual int countStartError() const = 0;

  virtual void addPoints(std::vector<Point>& points, int x, int y, const Color & color) const;

  virtual int getStartX() const = 0;

  virtual int getStartY() const = 0;

  virtual bool isDiagonalOrHorizontal(int error) const;
  
  virtual bool isDiagonalOrVertical(int error) const;

  virtual int deltaX() const;

  virtual int deltaY() const;

  virtual bool stopCondition(int x, int y, int limitX, int limitY) const;

  virtual int countVerticalError(int y, int error) const = 0;

  virtual int countHorizontalError(int x, int error) const = 0;

  virtual int countDiagonalError(int x, int y, int error) const = 0;

  Point zeroPoint;

  int maxX;
  
  int maxY;

};