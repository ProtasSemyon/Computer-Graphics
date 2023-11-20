#include "Canvas.hpp"
#include "core/utils/Utils.hpp"
#include "objectPool/ObjectPool.hpp"

std::vector<PointVector> Canvas::getPointsForDrawing(const Point &screenCenter) const {
  auto objs = ObjectPool::getInstance().getObjects();

  std::vector<PointVector> points;
  for (const auto& object : objs) {
    auto pointsForAdd = object->getPointsForDrawing();
    convertSystemObjectToScreenObject(pointsForAdd, screenCenter);
    points.emplace_back(pointsForAdd);
  }

  if (dynamicObj) {
    auto pointsForAdd = dynamicObj->getPointsForDrawing();
    convertSystemObjectToScreenObject(pointsForAdd, screenCenter);
    points.emplace_back(pointsForAdd);
  }

  return points;
}

void Canvas::resetDynamicObj() {
  dynamicObj = nullptr;
}

void Canvas::setDynamicObj(const std::shared_ptr<IObject>& obj) {
  dynamicObj = obj;
}

void Canvas::convertSystemObjectToScreenObject(PointVector &points, const Point &screenCenter) const {
  for (auto &point : points) {
    point = systemPointToScreenPoint(point, screenCenter);
  }
}
