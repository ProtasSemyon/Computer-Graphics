#include "modes/lines/ILineMode.hpp"

class LineWuMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;

private:
  void addPoint(std::vector<Point> &points, int x, int y, float color, bool inverted) const;
};