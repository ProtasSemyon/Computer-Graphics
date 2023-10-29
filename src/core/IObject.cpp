#include "IObject.hpp"
#include <iostream>

IObject::IObject(const std::vector<Point>& points) : points(points) {
  std::cout << "bruh" << std::endl;
}
