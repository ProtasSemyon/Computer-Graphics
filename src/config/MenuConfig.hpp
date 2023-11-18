#include "modes/IMode.hpp"
#include <unordered_map>
#include <string>
#include <memory>


const std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<IMode>>> selectedModeConfig {
  {"Cone line", {
    {"Parabola", std::make_shared<IMode>()},
    {"Hyperbola", nullptr},
    {"Circle", nullptr},
    {"Ellipse", nullptr}
  }
  },
  {"Line", {
    {"Wu", nullptr},
    {"Bresenhem", nullptr},
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