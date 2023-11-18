#include "Circle.hpp"
#include "core/drawer/Drawer.hpp"
#include "objects/lineCone/Constant.hpp"
#include <stdexcept>

Circle::Circle(const PointVector& points, const Color &color) : IObject(points, color) {
}

PointVector Circle::getPointsForDrawing() const {
  if (basePoints.size() != 2) {
    throw std::invalid_argument("Must be two points");
  }

  return Drawer::getCircle(basePoints.at(0), basePoints.at(1), maxPoint, color);
}