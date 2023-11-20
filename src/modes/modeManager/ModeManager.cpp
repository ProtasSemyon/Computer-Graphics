#include "ModeManager.hpp"
#include "modes/default/DefaultMode.hpp"

void ModeManager::enterMode(const std::shared_ptr<IMode>& mode) {
  modes.push(mode);
}

void ModeManager::exitCurrentMode() {
  modes.pop();
}

std::shared_ptr<IMode> ModeManager::getCurrentMode() {
  return modes.top();
}

ModeManager& ModeManager::getInstance() {
  static ModeManager inst;
  return inst;
}


