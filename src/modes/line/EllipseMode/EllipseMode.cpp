#include "EllipseMode.hpp"
#include "objects/lineCone/ellipse/Ellipse.hpp"

std::shared_ptr<IObject> EllipseMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<Ellipse>(points);
}




