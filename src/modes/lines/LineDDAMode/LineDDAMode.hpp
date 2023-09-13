#include "modes/lines/ILineMode.hpp"

class LineDDAMode : public ILineMode {
protected:
  std::vector<std::pair<int, int> > getLine(std::pair<int, int> startPoint, std::pair<int, int> endPoint) override;
};