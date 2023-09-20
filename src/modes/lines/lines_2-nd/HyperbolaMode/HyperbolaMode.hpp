#pragma once

#include "modes/lines/lines_2-nd/ILine2-ndMode.hpp"


class HyperbolaMode : public ILine2_ndMode {

protected:
  int a;

  int b;
private:
  void initialisation(const Point &startPoint, const Point &endPoint) final;
};

class HorizontalHyperbolaMode : public HyperbolaMode {
private:
  int countVerticalError(int y, int error) const final;

  int countHorizontalError(int x, int error) const final;

  int countDiagonalError(int x, int y, int error) const final;

  int countStartError() const final;

  int getStartX() const final;

  int getStartY() const final;
};

class VerticalHyperbolaMode : public HyperbolaMode {
private:
  int countVerticalError(int y, int error) const final;

  int countHorizontalError(int x, int error) const final;

  int countDiagonalError(int x, int y, int error) const final;

  int countStartError() const final;

  int getStartX() const final;

  int getStartY() const final;

  bool isDiagonalOrHorizontal(int error) const final;
  
  bool isDiagonalOrVertical(int error) const final;
};