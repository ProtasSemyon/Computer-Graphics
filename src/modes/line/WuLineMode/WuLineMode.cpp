#include "WuLineMode.hpp"
#include "objects/line/bresenhem/BresenhemLine.hpp"
#include "objects/line/wu/WuLine.hpp"

std::shared_ptr<IObject> WuLineMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<BresenhemLine>(points);
}
