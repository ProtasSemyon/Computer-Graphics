#include "BresenhemLine.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

BresenhemLine::BresenhemLine(const PointVector& points, const Color &color) : IObject(points, color) {
}

PointVector BresenhemLine::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getBresenhemLine(basePoints.at(0), basePoints.at(1), color);
}
