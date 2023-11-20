#pragma once

#include "core/point/Point.hpp"
int ipart(float x);

float fpart(float x);

void osOpenInShell(const char* path);

Point screenPointToSystemPoint(const Point & point, const Point & zeroPoint);

Point systemPointToScreenPoint(const Point & point, const Point & zeroPoint);