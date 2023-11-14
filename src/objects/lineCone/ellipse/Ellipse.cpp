#include "Ellipse.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

Ellipse::Ellipse(const PointVector& points, const Color &color) : IObject(points, color) {
}

PointVector Ellipse::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getEllipse(basePoints.at(0), basePoints.at(1), color);
}