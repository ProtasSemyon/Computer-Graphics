#include "Drawer.hpp"
#include "core/drawer/CurveDrawer/BSplineDrawer/BSplineDrawer.hpp"
#include "core/drawer/CurveDrawer/BesieCurveDrawer/BesieCurveDrawer.hpp"
#include "core/drawer/CurveDrawer/HermitCurveDrawer/HermitCurveDrawer.hpp"

PointVector getHermitCurve(const PointVector& controlPoints, const Color& color) {
  static HermitCurveDrawer hermitCurveDrawer;
  return hermitCurveDrawer.getPoints(controlPoints, color);
}

PointVector getBesieCurve(const PointVector& controlPoints, const Color& color) {
  static BesieCurveDrawer besieCurveDrawer;
  return besieCurveDrawer.getPoints(controlPoints, color);
}

PointVector getBSplineCurve(const PointVector& controlPoints, bool isClosed, const Color& color) {
  static BSplineDrawer bsplineDrawer;
  return bsplineDrawer.getPoints(controlPoints, color, isClosed);
}