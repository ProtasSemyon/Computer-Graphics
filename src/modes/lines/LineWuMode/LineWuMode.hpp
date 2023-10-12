#include "modes/lines/ILineMode.hpp"

class LineWuMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;

private:
  void addPoint(std::vector<Point> &points, int x, int y, float color, bool inverted) const;

  std::vector<Point> getVerticalLine(Point startPoint, Point endPoint) const;

  std::vector<Point> getHorizontalLine(Point startPoint, Point endPoint) const;

  std::vector<Point> getDiagonalLine(Point startPoint, Point endPoint) const;

};