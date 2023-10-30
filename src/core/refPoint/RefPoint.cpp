#include "RefPoint.hpp"

#include <GLFW/glfw3.h>
#include <cmath>

RefPoint::RefPoint(int x, int y, int r) : x(x), y(y), r(r) {}

void RefPoint::draw() const {
  glLineWidth(2);
  glBegin(GL_LINE_LOOP);
    glVertex2i(x - r, y - r);
    glVertex2i(x + r, y - r);
    glVertex2i(x + r, y + r);
    glVertex2i(x - r, y + r);
  glEnd();
}

RefPoint::operator Point() const {
  return {x, y};
}

bool RefPoint::isPressed(const Point &pressPoint) const {
  return std::abs(x - pressPoint.x) < r && std::abs(y - pressPoint.y) < r;
}

void RefPoint::setPosition(int xpos, int ypos) {
  x = xpos;
  y = ypos;
}


