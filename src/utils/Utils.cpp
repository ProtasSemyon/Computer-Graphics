#include "Utils.hpp"
#include <cstdio>
#include <cstdlib>
#include <string>

void osOpenInShell(const char* path) {
	const char* open_executable = "xdg-open";
	std::string command;
	snprintf(command.data(), 256, "%s \"%s\"", open_executable, path);
	system(command.c_str());
}