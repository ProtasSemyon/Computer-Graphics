#pragma once

#include "modes/IMode.hpp"
#include <memory>
#include <stack>

class ModeManager {
public:
  void enterMode(const std::shared_ptr<IMode>& mode);

  void exitCurrentMode();

  std::shared_ptr<IMode> getCurrentMode();

  static ModeManager& getInstance();

private:
  std::stack<std::shared_ptr<IMode>> modes;

  ModeManager() = default;
  ModeManager(const ModeManager&) = default;
  ModeManager& operator=(ModeManager&) = default;
};