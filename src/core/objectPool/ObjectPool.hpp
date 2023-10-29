#pragma once

#include "core/IObject.hpp"
#include <memory>

class ObjectPool {
public:
  void addObject(std::shared_ptr<IObject> object);

  template<class IType>
  std::vector<std::shared_ptr<IType>> get();

  static ObjectPool& getInstance();
private:
  std::vector<std::shared_ptr<IObject>> objects;

  ObjectPool() = default;
  ObjectPool(const ObjectPool&) = default;
  ObjectPool& operator=(ObjectPool&) = default;
};

template<class IType>
std::vector<std::shared_ptr<IType>> ObjectPool::get() {
  std::vector<std::shared_ptr<IType>> result;

  for (const auto & object : objects) {
    if (auto castResult = std::dynamic_pointer_cast<IType>(object)) {
      result.emplace_back(castResult);
    }
  }

  return result;
}