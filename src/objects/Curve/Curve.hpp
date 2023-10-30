#pragma once

#include "objects/IDrawable.hpp"
#include "objects/IEditable.hpp"

class Curve : public IDrawable, public IEditable {
public:
  Curve() = default;

  Curve(const std::vector<Point> &points, const std::vector<RefPoint> &refPoints, const std::shared_ptr<IDrawer> &drawer);
};