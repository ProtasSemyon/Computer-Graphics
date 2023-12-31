#include "ObjectPool.hpp"

void ObjectPool::addObject(std::shared_ptr<IObject> object) {
  objects.emplace_back(object);
}

void ObjectPool::deleteObject(const std::shared_ptr<IObject> &objectAddr) {
  for (size_t i  = 0; i < objects.size(); i++) {
    auto object = objects[i];
    if (object == objectAddr) {
      objects.erase(objects.begin() + i);
      break;
    }
  }
}


ObjectPool& ObjectPool::getInstance() {
  static ObjectPool instance;
  return instance;
}
