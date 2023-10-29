#pragma once

#include <GLFW/glfw3.h>

#include "core/IObject.hpp"

class IEditable : virtual public IObject {
public:
  IEditable() = default;

  IEditable(const std::vector<Point>& points);
};