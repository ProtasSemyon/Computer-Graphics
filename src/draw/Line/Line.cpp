#include "Line.hpp"

Line::Line(const std::vector<std::pair<int, int> > &points) : IDrawable(points) {}

void Line::draw() {
  glBegin( GL_POINTS );
  for(const auto& [x, y] : points) {
    glVertex2i(x, y);
  }
  glEnd();
}