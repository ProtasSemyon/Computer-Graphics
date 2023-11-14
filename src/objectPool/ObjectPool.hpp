#pragma once

#include "objects/IObject.hpp"
#include <memory>

class ObjectPool {
public:
  void addObject(const std::shared_ptr<IObject> &object);

  void deleteObject(const std::shared_ptr<IObject> &objectAddr);

  static ObjectPool& getInstance();

private:
  std::vector<std::shared_ptr<IObject>> objects;

  ObjectPool() = default;
  ObjectPool(const ObjectPool&) = default;
  ObjectPool& operator=(ObjectPool&) = default;
};