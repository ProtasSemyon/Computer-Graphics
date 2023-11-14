#include "DDALine.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

DDALine::DDALine(const PointVector& points, const Color &color) : IObject(points, color) {
}

PointVector DDALine::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getDDALine(basePoints.at(0), basePoints.at(1), color);
}
