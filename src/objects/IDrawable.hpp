#pragma once

#include <GLFW/glfw3.h>

#include "core/IObject.hpp"

class IDrawable : virtual public IObject {
public:
  IDrawable() = default;

  void draw() const;
};