#include "BesieCurve.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

BesieCurve::BesieCurve(const PointVector& points, const Color & color) : IObject(points, color) {
}

PointVector BesieCurve::getPointsForDrawing() const {
  if (basePoints.size() != 4) {
    throw std::invalid_argument("Must be four points");
  }

  return Drawer::getBesieCurve(basePoints, color);
}