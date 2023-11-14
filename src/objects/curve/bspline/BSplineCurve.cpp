#include "BSplineCurve.hpp"
#include "core/drawer/Drawer.hpp"
#include <stdexcept>

BSplineCurve::BSplineCurve(const PointVector& points, bool isClosed, const Color & color) : IObject(points, color), isClosed(isClosed) {
}

PointVector BSplineCurve::getPointsForDrawing() const {
  return Drawer::getBSplineCurve(basePoints, isClosed, color);
}