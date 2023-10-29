#include "DrawableObjectPool.hpp"

void DrawableObjectPool::draw() const {
  for (const auto &object : objects) {
    if(object) {
      object->draw();
    }
  }
}

void DrawableObjectPool::addObject(IDrawable *object) {
  objects.emplace_back(object);
}

DrawableObjectPool& DrawableObjectPool::getInstance() {
  static DrawableObjectPool instance;
  return instance;
}
