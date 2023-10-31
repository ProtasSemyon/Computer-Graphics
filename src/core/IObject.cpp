#include "IObject.hpp"
#include <iostream>

IObject::IObject(const std::vector<Point>& points) : points(points) {
}

void IObject::setPoints(const std::vector<Point>& newPoints) {
  points = newPoints;
}