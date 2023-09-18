#include <map>
#include <string>
#include <memory>

#include "modes/lines/LineDDAMode/LineDDAMode.hpp"
#include "modes/lines/LineBresenhemMode/LineBresenhemMode.hpp"
#include "modes/lines/LineWuMode/LineWuMode.hpp"

const std::map<std::string, std::map<std::string, std::shared_ptr<IMode>, std::less<>>, std::less<>> menuConfig {
  {"Line", {
    {"DDA", std::make_shared<LineDDAMode>()},
    {"Bresenhem", std::make_shared<LineBresenhemMode>()},
    {"Wu", std::make_shared<LineWuMode>()}
   }
  }
};