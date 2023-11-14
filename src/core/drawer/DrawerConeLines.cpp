#include "Drawer.hpp"
#include "core/drawer/ConeLinesDrawer/Circle/CircleDrawer.hpp"

#include <cmath>

int findRadius(const Point &startPoint, const Point &endPoint);

PointVector Drawer::getCircle(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color) {
  static CircleDrawer circleDrawer;
  circleDrawer.setMaxX(maxPoint.getX());
  circleDrawer.setMaxY(maxPoint.getY());
  return circleDrawer.getLine(startPoint, endPoint, color);
}

PointVector Drawer::getEllipse(const Point& startPoint, const Point& endPoint, const Color& color) {

}

PointVector Drawer::getHyperbola(const Point& startPoint, const Point& endPoint, bool isHorizontal, const Color& color) {

}

PointVector Drawer::getParabola(const Point& startPoint, const Point& endPoint, const Color& color) {

}
