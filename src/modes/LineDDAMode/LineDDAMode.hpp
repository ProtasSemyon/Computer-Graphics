#include "modes/IMode.hpp"

class LineDDAMode: public IMode {
public:
  LineDDAMode() = default;

  void draw() override;

  void update() override;
    
};

