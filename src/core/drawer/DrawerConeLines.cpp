#include "Drawer.hpp"
#include "core/drawer/ConeLinesDrawer/Circle/CircleDrawer.hpp"
#include "core/drawer/ConeLinesDrawer/Ellipse/EllipseDrawer.hpp"
#include "core/drawer/ConeLinesDrawer/Hyperbola/HyperbolaDrawer.hpp"
#include "core/drawer/ConeLinesDrawer/Parabola/ParabolaDrawer.hpp"

#include <cmath>

int findRadius(const Point &startPoint, const Point &endPoint);

PointVector Drawer::getCircle(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static CircleDrawer circleDrawer;
  circleDrawer.setMaxX(maxPoint.getX());
  circleDrawer.setMaxY(maxPoint.getY());
  return circleDrawer.getLine(startPoint, endPoint, color);
}

PointVector Drawer::getEllipse(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static EllipseDrawer ellipseDrawer;
  ellipseDrawer.setMaxX(maxPoint.getX());
  ellipseDrawer.setMaxY(maxPoint.getY());
  return ellipseDrawer.getLine(startPoint, endPoint, color);
}

PointVector Drawer::getHyperbola(const Point& startPoint, const Point& endPoint, const Point& maxPoint, bool isHorizontal, const Color& color) {
  if(isHorizontal) {
    static HorizontalHyperbolaDrawer horizontalHyperbolaDrawer;
    horizontalHyperbolaDrawer.setMaxX(maxPoint.getX());
    horizontalHyperbolaDrawer.setMaxY(maxPoint.getY());
    return horizontalHyperbolaDrawer.getLine(startPoint, endPoint, color);
  }
  static VerticalHyperbolaDrawer verticalHyperbolaDrawer;
  verticalHyperbolaDrawer.setMaxX(maxPoint.getX());
  verticalHyperbolaDrawer.setMaxY(maxPoint.getY());
  return verticalHyperbolaDrawer.getLine(startPoint, endPoint, color);
}

PointVector Drawer::getParabola(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static ParabolaDrawer parabolaDrawer;
  parabolaDrawer.setMaxX(maxPoint.getX());
  parabolaDrawer.setMaxY(maxPoint.getY());
  return parabolaDrawer.getLine(startPoint, endPoint, color);
}
