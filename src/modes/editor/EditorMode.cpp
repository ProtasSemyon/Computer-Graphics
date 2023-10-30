#include "EditorMode.hpp"
#include "objects/IEditable.hpp"

std::vector<RefPoint> EditorMode::refPoints;

std::vector<Point> EditorMode::points;

RefPoint * EditorMode::pressedPoint;

bool EditorMode::pressed = false;

bool EditorMode::closed = false;


EditorMode::EditorMode(const std::shared_ptr<IEditable>& editObj, const std::shared_ptr<IMode> &returnMode) : drawer(editObj->getDrawMode()), returnMode(returnMode)  {
  refPoints = editObj->getRefPoints();
  closed = false;
}


void EditorMode::setMouseCallbackInHeritor() {
  glfwSetMouseButtonCallback(window->getWindow(), EditorMode::mouseButtonCallback);
}

void EditorMode::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    for (auto& refPoint : refPoints) {
      if (refPoint.isPressed({(int)xpos, (int)ypos})) {
        pressedPoint = &refPoint;
      }
    }

    pressed = true;
  }
  
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    pressedPoint = nullptr;
    pressed = false;
  }

}

void EditorMode::draw() {
  if (window->getIsMenuOpened()) {
    return;
  }

  if (pressed && pressedPoint) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window->getWindow(), &xpos, &ypos);
    pressedPoint->setPosition(xpos, ypos);
  }

  for (const auto& refPoint : refPoints) {
    refPoint.draw();
  }

  std::vector<Point> p;
  Point startPoint = refPoints[0];
  for (const Point& refPoint : refPoints) {
    p.emplace_back(refPoint.x - startPoint.x, startPoint.y - refPoint.y);
  }
  points = drawer->getPoints(p);

  for (auto& point : points) {
    point.toScreenPoint(refPoints[0]);
  }
  glBegin(GL_POINTS);
    for(const auto& point: points) {
      glVertex2i(point.x, point.y);
    }
  glEnd();

  if (closed) {
    returnMode->finishDraw(points, refPoints);
    window->setMode(returnMode.get());
  }
}

void EditorMode::setKeyCallback() {
  glfwSetKeyCallback(window->getWindow(), keyCallback);
}

void EditorMode::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == EXIT_MODE_KEY && action == GLFW_PRESS){
    closed = true;
  }
}

