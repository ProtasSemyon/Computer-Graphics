#pragma once

#include "modes/IMode.hpp"

class DefaultMode : public IMode {
public:
  void drawInCanvas(std::shared_ptr<Canvas> &canvas, const Point &centerPoint) override;
};