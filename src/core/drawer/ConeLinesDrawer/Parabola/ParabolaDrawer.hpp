#pragma once

#include "core/drawer/ConeLinesDrawer/ConeLinesDrawer.hpp"
class ParabolaDrawer : public ConeLinesDrawer {
private:
  void initialisation(const Point &startPoint, const Point &endPoint) final;

  void addPoints(std::vector<Point>& points, int x, int y, const Color & color) const final;

  int countVerticalError(int y, int error) const final;

  int countHorizontalError(int x, int error) const final;

  int countDiagonalError(int x, int y, int error) const final;

  int countStartError() const final;

  int getStartX() const final;

  int getStartY() const final;

  bool isDiagonalOrHorizontal(int error) const final;
  
  bool isDiagonalOrVertical(int error) const final;

  bool isNegative = false;

  int p;
};