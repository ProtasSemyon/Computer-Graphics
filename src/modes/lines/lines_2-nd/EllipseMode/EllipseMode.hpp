#pragma once

#include "modes/lines/lines_2-nd/ILine2-ndMode.hpp"

class EllipseMode : public ILine2_ndMode {
private:
  int a;

  int b;

  void initialisation(const Point &startPoint, const Point &endPoint) final;

  int countVerticalError(int y, int error) const final;

  int countHorizontalError(int x, int error) const final;

  int countDiagonalError(int x, int y, int error) const final;

  int countStartError() const final;

  int getStartX() const final;

  int getStartY() const final;

  int deltaY() const final;

  bool stopCondition(int x, int y, int limitX, int limitY) const final;

};