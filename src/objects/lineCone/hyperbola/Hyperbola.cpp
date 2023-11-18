#include "Hyperbola.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>
#include "objects/lineCone/Constant.hpp"


Hyperbola::Hyperbola(const PointVector& points, bool isHorizontal, const Color & color) : IObject(points, color), isHorizontal(isHorizontal) {
}

PointVector Hyperbola::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getHyperbola(basePoints.at(0), basePoints.at(1), maxPoint, isHorizontal, color);
}