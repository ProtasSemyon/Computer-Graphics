#include "BresenhemLineMode.hpp"
#include "objects/line/bresenhem/BresenhemLine.hpp"

std::shared_ptr<IObject> BresenhemLineMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<BresenhemLine>(points);
}
