#include "Parabola.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

Parabola::Parabola(const PointVector& points, const Color &color) : IObject(points, color) {
}

PointVector Parabola::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getParabola(basePoints.at(0), basePoints.at(1), color);
}