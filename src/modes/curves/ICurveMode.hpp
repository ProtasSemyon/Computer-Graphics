#pragma once

#include "core/refPoint/RefPoint.hpp"
#include "modes/IMode.hpp"
#include "modes/IDrawer.hpp"


class ICurveMode : public IMode, public IDrawer {
public:
  void draw() override;

  std::vector<Point> getPoints(const std::vector<Point> &points) override;

private:
  virtual std::shared_ptr<ICurveMode> getPtr() = 0;

  void setMouseCallbackInHeritor() override;

  void startEditMode(const std::shared_ptr<IEditable>& objForEdit) override;

  static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

  virtual std::vector<Point> getCurve(const std::vector<Point>& points) = 0;

  virtual bool setRefPointStopCondition();

  static std::vector<Point> currentLine;

  static std::vector<RefPoint> refPoints;

  static Point startPoint;

  static std::vector<Point> points;

  void finishDraw(const std::vector<Point> &objPoints, const std::vector<RefPoint> &objRefPoints);

};