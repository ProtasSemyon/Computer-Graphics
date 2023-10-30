#include "IEditable.hpp"

std::vector<RefPoint> IEditable::getRefPoints() const {
  return refPoints;
}

std::shared_ptr<IDrawer> IEditable::getDrawMode() const {
  return drawer;
}

IEditable::IEditable(const std::vector<RefPoint>& refPoints, const std::shared_ptr<IDrawer> &drawer) : refPoints(refPoints), drawer(drawer) {}

