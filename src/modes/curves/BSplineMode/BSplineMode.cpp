#include "BSplineMode.hpp"

#include <cmath>

const int POINT_MULTIPLICATOR = 10;

const int FINISH_SPLINE_KEY = GLFW_KEY_ENTER;

const int CLOSE_SPLINE_KEY = GLFW_KEY_SPACE;

bool BSplineMode::finishSpline = false;

bool BSplineMode::closeSpline = true;

BSplineMode::BSplineMode(bool isClosed) : isClosed(isClosed) {

}


void BSplineMode::setPoints(const Point &P1, const Point &P2, const Point& P3, const Point& P4) {
  multiplicateMatrix = Matrix(
    {{(double)P1.x, (double)P1.y},
    {(double)P2.x, (double)P2.y},
    {(double)P3.x, (double)P3.y},
    {(double)P4.x, (double)P4.y}}
  );
}

Point BSplineMode::getPoint(double time) const {
  auto mulMatrix = Matrix({std::pow(time, 3), std::pow(time, 2), time, 1});
  auto result = ((1.0/6.0) * mulMatrix * bsplineMatrix * multiplicateMatrix).getVector();
  return {(int)result[0], (int)result[1]};
}

std::vector<Point> BSplineMode::getCurve(const std::vector<Point>& points) {
  finishSpline = false;
  auto usedPoints = points;
  if (isClosed) {
    for (int i = 0; i < 4; i++) {
      usedPoints.emplace_back(usedPoints[i]);
    }
  } else {
    usedPoints.insert(usedPoints.begin(), usedPoints[0]);
    usedPoints.emplace_back(usedPoints[usedPoints.size() - 1]);
  }
  std::vector<Point> result;

  for (int i = 0; i < usedPoints.size() - 3; i++) {
    setPoints(usedPoints[i], usedPoints[i + 1], usedPoints[i + 2], usedPoints[i + 3]);

    //auto delta = points[0] - points[1];
    int maxTime = 1000;//std::max(std::abs(delta.x), std::abs(delta.y)) * POINT_MULTIPLICATOR + 2000;

    for (int time = 0; time <= maxTime; time++) {
      result.emplace_back(getPoint((double)(time)/maxTime));
    }
  }
  return result;
}

std::shared_ptr<ICurveMode> BSplineMode::getPtr() {
  return std::shared_ptr<BSplineMode>(this);
}

bool BSplineMode::setRefPointStopCondition() {
  return finishSpline && points.size() >= REF_POINT_COUNT;
}

void BSplineMode::setKeyCallback() {
  glfwSetKeyCallback(window->getWindow(), BSplineMode::keyCallback);
}

void BSplineMode::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == FINISH_SPLINE_KEY && action == GLFW_PRESS)
    finishSpline = true;

  // if (key == CLOSE_SPLINE_KEY && action == GLFW_PRESS)
  //   closeSpline = true;
}

