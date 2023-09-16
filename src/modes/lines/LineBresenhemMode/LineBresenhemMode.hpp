#include "modes/lines/ILineMode.hpp"

class LineBresenhemMode : public ILineMode {
protected:
  std::vector<Point> getLine(Point startPoint, Point endPoint) override;
};