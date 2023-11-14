#include "WuLine.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

WuLine::WuLine(const PointVector& points, const Color &color) : IObject(points, color) {
}

PointVector WuLine::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getWuLine(basePoints.at(0), basePoints.at(1), color);
}
