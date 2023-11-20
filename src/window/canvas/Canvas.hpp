#pragma once

#include "core/point/Point.hpp"
#include "objects/IObject.hpp"
#include <memory>

class Canvas {
public:
  std::vector<PointVector> getPointsForDrawing(const Point &screenCenter) const;
  
  void setDynamicObj(const std::shared_ptr<IObject>& obj);

  void resetDynamicObj();
private:
  void convertSystemObjectToScreenObject(PointVector &points, const Point &screenCenter) const;

  std::shared_ptr<IObject> dynamicObj;
};