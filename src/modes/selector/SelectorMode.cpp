#include "SelectorMode.hpp"
#include "modes/editor/EditorMode.hpp"
#include "objects/IEditable.hpp"

std::shared_ptr<IEditable> SelectorMode::selectedObject;

std::vector<std::shared_ptr<IEditable>> SelectorMode::editableObjects;

const int DISTANCE = 20;

void SelectorMode::draw() {
  if (selectedObject) {
    ObjectPool::getInstance().deleteObject(selectedObject);
    startEditMode(selectedObject);
  }
}

void SelectorMode::setMouseCallbackInHeritor() {
  glfwSetMouseButtonCallback(window->getWindow(), SelectorMode::mouseButtonCallback);
}

void SelectorMode::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
  ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    double xpos;
    double ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    editableObjects = ObjectPool::getInstance().get<IEditable>();

    if (editableObjects.empty()) {
      return;
    }

    Point clickPoint(xpos, ypos);
    int minimalDistanceIndex = 0;
    int currentMinimalDistance = editableObjects[0]->getDistanceFromPoint(clickPoint);

    for (int i = 1; i < editableObjects.size(); i++) {
      int currentDistance = editableObjects[i]->getDistanceFromPoint(clickPoint);
      if (currentMinimalDistance > currentDistance) {
        currentMinimalDistance = currentDistance;
        minimalDistanceIndex = i;
      }
    }

    if (currentMinimalDistance <= DISTANCE) {
      selectedObject = editableObjects[minimalDistanceIndex];
    }
  }
}

void SelectorMode::finishDraw(const std::vector<Point> &objPoints, const std::vector<RefPoint> &objRefPoints) {
  selectedObject->setPoints(objPoints);
  selectedObject->setRefPoints(objRefPoints);

  ObjectPool::getInstance().addObject(selectedObject);
  selectedObject = nullptr;
}

void SelectorMode::startEditMode(const std::shared_ptr<IEditable>& objForEdit) {
  window->setMode(new EditorMode(selectedObject, std::shared_ptr<IMode>(this)));
}


