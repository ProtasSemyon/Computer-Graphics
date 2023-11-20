#include "ParabolaMode.hpp"
#include "objects/lineCone/parabola/Parabola.hpp"

std::shared_ptr<IObject> ParabolaMode::getDrawObject(const PointVector &points) const {
  return std::make_shared<Parabola>(points);
}




