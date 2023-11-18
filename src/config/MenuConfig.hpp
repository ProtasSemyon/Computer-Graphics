#include <unordered_map>
#include <string>
#include <memory>

//TODO: change int to something

const std::unordered_map<std::string, std::unordered_map<std::string, int *>> selectedModeConfig {
  {"Cone line", {
    {"Parabola", nullptr},
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