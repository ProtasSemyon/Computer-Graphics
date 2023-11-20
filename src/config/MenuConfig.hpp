#include "modes/line/BresenhemLineMode/BresenhemLineMode.hpp"
#include "modes/line/CircleMode/CircleMode.hpp"
#include "modes/line/DDALineMode/DDALineMode.hpp"
#include "modes/line/EllipseMode/EllipseMode.hpp"
#include "modes/line/HyperbolaMode/HyperbolaMode.hpp"
#include "modes/line/ParabolaMode/ParabolaMode.hpp"
#include "modes/line/WuLineMode/WuLineMode.hpp"
#include <unordered_map>
#include <string>
#include <memory>


const std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<IMode>>> selectedModeConfig {
  {"Cone line", {
    {"Parabola", std::make_shared<ParabolaMode>()},
    {"Hyperbola", std::make_shared<HyperbolaMode>()},
    {"Circle", std::make_shared<CircleMode>()},
    {"Ellipse", std::make_shared<EllipseMode>()}
  }
  },
  {"Line", {
    {"Wu", std::make_shared<WuLineMode>()},
    {"Bresenhem", std::make_shared<BresenhemLineMode>()},
    {"DDA", std::make_shared<DDALineMode>()}
  }
  },
  {"Curve", {
    {"Hermit Curve", nullptr},
    {"Besie Curve", nullptr},
    {"B-Spline", nullptr}
    }
  }
  }
;