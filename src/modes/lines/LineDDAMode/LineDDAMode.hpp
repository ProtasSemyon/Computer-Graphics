#include "modes/lines/ILineMode.hpp"

class LineDDAMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;
};