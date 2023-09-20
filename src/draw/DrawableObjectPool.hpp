#pragma once

#include "draw/IDrawable.hpp"

class DrawableObjectPool {
public:
  void addObject(IDrawable * object);

  void draw() const;

  static DrawableObjectPool& getInstance();
private:
  std::vector<IDrawable *> objects;

  DrawableObjectPool() = default;
  DrawableObjectPool(const DrawableObjectPool&) = default;
  DrawableObjectPool& operator=(DrawableObjectPool&) = default;
};