#include "HermitCurve.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

HermitCurve::HermitCurve(const PointVector& points, const Color & color) : IObject(points, color) {
}

PointVector HermitCurve::getPointsForDrawing() const {
  if (basePoints.size() != 4) {
    throw std::invalid_argument("Must be four points");
  }

  return Drawer::getHermitCurve(basePoints, color);
}