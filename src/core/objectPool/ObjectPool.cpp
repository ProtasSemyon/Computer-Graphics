#include "ObjectPool.hpp"

void ObjectPool::addObject(IObject *object) {
  objects.emplace_back(object);
}

ObjectPool& ObjectPool::getInstance() {
  static ObjectPool instance;
  return instance;
}
