#include "IDrawable.hpp"

void IDrawable::draw() const {
  glBegin( GL_POINTS );
  for(const auto& [x, y, color] : points) {
    glColor4f(color.r, color.g, color.b, color.a);
    glVertex2i(x, y);
  }
  glEnd();
}

