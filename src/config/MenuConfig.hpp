#include <unordered_map>
#include <string>
#include <memory>

#include "modes/lines/LineDDAMode/LineDDAMode.hpp"
#include "modes/lines/LineBresenhemMode/LineBresenhemMode.hpp"
#include "modes/lines/LineWuMode/LineWuMode.hpp"
#include "modes/lines/lines_2-nd/CircleMode/CircleMode.hpp"

const std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<IMode>>> menuConfig {
  {"2-nd order line", {
    {"Circle", std::make_shared<CircleMode>()}
  }
  },
  {"Line", {
    {"Wu", std::make_shared<LineWuMode>()},
    {"Bresenhem", std::make_shared<LineBresenhemMode>()},
    {"DDA", std::make_shared<LineDDAMode>()}
  }
  }
};