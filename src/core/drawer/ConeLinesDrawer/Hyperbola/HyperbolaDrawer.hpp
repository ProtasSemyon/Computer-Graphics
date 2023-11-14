#pragma once

#include "core/drawer/ConeLinesDrawer/ConeLinesDrawer.hpp"


class HyperbolaDrawer : public ConeLinesDrawer {
protected:
  int a;

  int b;

private:
  void initialisation(const Point &startPoint, const Point &endPoint) final;
};

class HorizontalHyperbolaDrawer : public HyperbolaDrawer {
private:
  int countVerticalError(int y, int error) const final;

  int countHorizontalError(int x, int error) const final;

  int countDiagonalError(int x, int y, int error) const final;

  int countStartError() const final;

  int getStartX() const final;

  int getStartY() const final;
};

class VerticalHyperbolaDrawer : public HyperbolaDrawer {
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