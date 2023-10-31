#pragma once

#include "modes/curves/ICurveMode.hpp"
#include "core/matrix/Matrix.hpp"
#include "core/point/Point.hpp"

class BSplineMode : public ICurveMode {
public:
  BSplineMode(bool isClosed = false);

  std::vector<Point> getCurve(const std::vector<Point>& points) override;

protected:
  void setKeyCallback() override;

private:

  std::shared_ptr<ICurveMode> getPtr() override;

  bool setRefPointStopCondition() override;

  void setPoints(const Point &startPoint, const Point &endPoint, const Point& startPointTangent, const Point& endPointTangent);

  static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

  Point getPoint(double time) const;

  const Matrix bsplineMatrix = Matrix(
 {{-1, 3, -3, 1},
  {3, -6, 3, 0},
  {-3, 0, 3, 0},
  {1 ,4, 1, 0}});

  Matrix multiplicateMatrix;

  static bool finishSpline;

  static bool closeSpline;

  bool isClosed;
};