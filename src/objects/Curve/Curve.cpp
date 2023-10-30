#include "Curve.hpp"

Curve::Curve(const std::vector<Point> &points, const std::vector<RefPoint> &refPoints, const std::shared_ptr<IDrawer> &drawer) : IObject(points), IEditable(refPoints, drawer) {
  
}
