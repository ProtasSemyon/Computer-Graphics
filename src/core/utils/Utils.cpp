#include "Utils.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>

int ipart(float x) {
  return static_cast<int>(x);
}

float fpart(float x) {
  return x - ipart(x);
}

void osOpenInShell(const char* path) {
	const char* open_executable = "xdg-open";
	std::string command;
	snprintf(command.data(), 256, "%s \"%s\"", open_executable, path);
	system(command.c_str());
}

Point screenPointToSystemPoint(const Point & point, const Point & zeroPoint) {
	return {point.getX() - zeroPoint.getX(), zeroPoint.getY() - point.getY()};
}

Point systemPointToScreenPoint(const Point & point, const Point & zeroPoint) {
	return {point.getX() + zeroPoint.getX(), zeroPoint.getY() - point.getY()};
}