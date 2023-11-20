#include "DDALineMode.hpp"
#include "objects/line/dda/DDALine.hpp"

std::shared_ptr<IObject> DDALineMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<DDALine>(points);
}
