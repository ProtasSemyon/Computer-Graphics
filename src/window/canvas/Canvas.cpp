#include "Canvas.hpp"
#include "objectPool/ObjectPool.hpp"

std::vector<PointVector> Canvas::getPointsForDrawing() const {
  auto objs = ObjectPool::getInstance().getObjects();

  std::vector<PointVector> points;
  for (const auto& object : objs) {
    points.emplace_back(object->getPointsForDrawing());
  }

  if (dynamicObj) {
    points.emplace_back(dynamicObj->getPointsForDrawing());
  }

  return points;
}

void Canvas::resetDynamicObj() {
  dynamicObj = nullptr;
}

void Canvas::setDynamicObj(const std::shared_ptr<IObject>& obj) {
  dynamicObj = obj;
}


