#include "modes/line/BresenhemLineMode/BresenhemLineMode.hpp"
#include "modes/line/CircleMode/CircleMode.hpp"
#include "modes/line/HyperbolaMode/HyperbolaMode.hpp"
#include <unordered_map>
#include <string>
#include <memory>


const std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<IMode>>> selectedModeConfig {
  {"Cone line", {
    {"Parabola", nullptr},
    {"Hyperbola", std::make_shared<HyperbolaMode>()},
    {"Circle", std::make_shared<CircleMode>()},
    {"Ellipse", nullptr}
  }
  },
  {"Line", {
    {"Wu", nullptr},
    {"Bresenhem", std::make_shared<BresenhemLineMode>()},
    {"DDA", nullptr}
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