#include "Utils.hpp"

int ipart(float x) {
  return static_cast<int>(x);
}

float fpart(float x) {
  return x - ipart(x);
}