#include "CircleMode.hpp"
#include "objects/lineCone/circle/Circle.hpp"

std::shared_ptr<IObject> CircleMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<Circle>(points);
}




