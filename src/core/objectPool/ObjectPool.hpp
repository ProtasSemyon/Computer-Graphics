#pragma once

#include "core/IObject.hpp"

class ObjectPool {
public:
  void addObject(IObject * object);

  template<class IType>
  std::vector<IType*> get();

  static ObjectPool& getInstance();
private:
  std::vector<IObject*> objects;

  ObjectPool() = default;
  ObjectPool(const ObjectPool&) = default;
  ObjectPool& operator=(ObjectPool&) = default;
};

template<class IType>
std::vector<IType*> ObjectPool::get() {
  std::vector<IType*> result;

  for (const auto & object : objects) {
    if (auto* castResult = dynamic_cast<IType*>(object)) {
      result.emplace_back(castResult);
    }
  }

  return result;
}