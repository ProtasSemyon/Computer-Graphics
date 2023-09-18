#pragma once

struct Color {
  Color();
  Color(float red, float green, float blue, float alpha);

  float r;
  float g;
  float b;
  float a;
};

const Color BLACK(0.0f, 0.0f, 0.0f, 1.0f);
const Color WHITE(1.0f, 1.0f, 1.0f, 1.0f);

struct Point {
  Point() = default;
  Point(int x, int y);
  Point(int x, int y, Color color);
  int x;
  int y;
  Color color;
};