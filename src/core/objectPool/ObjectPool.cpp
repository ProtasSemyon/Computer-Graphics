#include "ObjectPool.hpp"

void ObjectPool::addObject(std::shared_ptr<IObject> object) {
  objects.emplace_back(object);
}

ObjectPool& ObjectPool::getInstance() {
  static ObjectPool instance;
  return instance;
}
