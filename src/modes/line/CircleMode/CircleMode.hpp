#pragma once 

#include "modes/line/ILineMode.hpp"

class CircleMode : public ILineMode {
private:
  std::shared_ptr<IObject> getDrawObject(const PointVector &points) const override;

};