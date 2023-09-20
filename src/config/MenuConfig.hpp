#include <unordered_map>
#include <string>
#include <memory>

#include "modes/lines/LineDDAMode/LineDDAMode.hpp"
#include "modes/lines/LineBresenhemMode/LineBresenhemMode.hpp"
#include "modes/lines/LineWuMode/LineWuMode.hpp"
#include "modes/lines/lines_2-nd/CircleMode/CircleMode.hpp"
#include "modes/lines/lines_2-nd/EllipseMode/EllipseMode.hpp"
#include "modes/lines/lines_2-nd/HyperbolaMode/HyperbolaMode.hpp"


const std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<IMode>>> menuConfig {
  {"2-nd order line", {
    {"Vertical Hyperbola", std::make_shared<VerticalHyperbolaMode>()},
    {"Horizontal Hyperbola", std::make_shared<HorizontalHyperbolaMode>()},
    {"Ellipse", std::make_shared<EllipseMode>()},
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