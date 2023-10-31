#pragma once

#include "modes/IMode.hpp"

class SelectorMode : public IMode {
public:
  void draw() override;

  void setMouseCallbackInHeritor() override;

private:

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  void finishDraw(const std::vector<Point> &objPoints, const std::vector<RefPoint> &objRefPoints) override;

  void startEditMode(const std::shared_ptr<IEditable>& objForEdit) override;

  static std::shared_ptr<IEditable> selectedObject;

  static std::vector<std::shared_ptr<IEditable>> editableObjects;

};