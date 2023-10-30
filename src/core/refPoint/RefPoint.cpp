#include "RefPoint.hpp"

#include <GLFW/glfw3.h>

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
