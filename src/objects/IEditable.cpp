#include "IEditable.hpp"
#include <cmath>

std::vector<RefPoint> IEditable::getRefPoints() const {
  return refPoints;
}

std::shared_ptr<IDrawer> IEditable::getDrawMode() const {
  return drawer;
}

IEditable::IEditable(const std::vector<RefPoint>& refPoints, const std::shared_ptr<IDrawer> &drawer) : refPoints(refPoints), drawer(drawer) {}

void IEditable::setRefPoints(const std::vector<RefPoint>& newRefPoints) {
  refPoints = newRefPoints;
}

int IEditable::getDistanceFromPoint(const Point &point) const {
  int distance = -1;

  for (const auto& currPoint : points) {
    int currDistance = std::pow(currPoint.x - point.x, 2) + std::pow(currPoint.y - point.y, 2);
    distance = distance == -1 ? currDistance : std::min(distance, currDistance);
  }

  return distance;
}

