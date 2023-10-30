#include "ICurveMode.hpp"
#include "modes/editor/EditorMode.hpp"
#include "objects/Curve/Curve.hpp"

const int REF_POINT_COUNT = 4;

std::vector<Point> ICurveMode::currentLine;

std::vector<RefPoint> ICurveMode::refPoints;

std::vector<Point> ICurveMode::points;


Point ICurveMode::startPoint;


bool ICurveMode::setRefPointStopCondition() {
  return points.size() == REF_POINT_COUNT;
}

void ICurveMode::setMouseCallbackInHeritor() {
  glfwSetMouseButtonCallback(window->getWindow(), ICurveMode::mouseButtonCallback);
}

void ICurveMode::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (points.empty()) {
      startPoint = {(int)xpos, (int)ypos};
    }
    points.emplace_back(xpos - startPoint.x, (ypos - startPoint.y) * -1);
    refPoints.emplace_back(xpos, ypos);
  }
}

void ICurveMode::draw() {
  if (window->getIsMenuOpened()) {
    return;
  }

  for (const auto& refPoint : refPoints) {
    refPoint.draw();
  }

  if (setRefPointStopCondition()) {
    auto currentCurve = getCurve(points);
    for (auto & point : currentCurve) {
      point.toScreenPoint(startPoint);
    }

    startEditMode(std::make_shared<Curve>(currentCurve, refPoints, getPtr()));
  }
}

std::vector<Point> ICurveMode::getPoints(const std::vector<Point> &points) {
  return getCurve(points);
}

void ICurveMode::startEditMode(const std::shared_ptr<IEditable>& objForEdit) {
  window->setMode(new EditorMode(objForEdit, getPtr()));
}

void ICurveMode::finishDraw(const std::vector<Point> &objPoints, const std::vector<RefPoint> &objRefPoints) {
  ObjectPool::getInstance().addObject(std::make_shared<Curve>(objPoints, refPoints, getPtr()));

  refPoints.clear();
  points.clear();
}

