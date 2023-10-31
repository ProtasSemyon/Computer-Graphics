#pragma once

#include "core/IObject.hpp"
#include "core/refPoint/RefPoint.hpp"
#include "modes/IDrawer.hpp"
#include <memory>

class IEditable : virtual public IObject {
public:
  IEditable() = default;

  IEditable(const std::vector<RefPoint>& refPoints, const std::shared_ptr<IDrawer> &drawer);

  std::vector<RefPoint> getRefPoints() const;

  int getDistanceFromPoint(const Point &point) const;

  void setRefPoints(const std::vector<RefPoint>& newRefPoints);

  std::shared_ptr<IDrawer> getDrawMode() const;

private:
  std::vector<RefPoint> refPoints;

  std::shared_ptr<IDrawer> drawer;
};