#include <map>
#include <string>
#include <memory>

#include "modes/lines/LineDDAMode/LineDDAMode.hpp"

const std::map<std::string, std::map<std::string, std::shared_ptr<IMode>, std::less<>>, std::less<>> menuConfig {
  {"Line", {
            {"DDA", std::make_shared<LineDDAMode>()}
               }
      }
};