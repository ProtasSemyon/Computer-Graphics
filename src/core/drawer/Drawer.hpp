#pragma once

#include "core/point/Point.hpp"
#include <vector>


class Drawer {
public:
  static std::vector<Point> getDDALine(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static std::vector<Point> getBresenhemLine(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static std::vector<Point> getWuLine(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static std::vector<Point> getCircle(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color = BLACK);

  static std::vector<Point> getEllipse(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static std::vector<Point> getHyperbola(const Point& startPoint, const Point& endPoint, bool isHorizontal = true, const Color& color = BLACK);

  static std::vector<Point> getParabola(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static std::vector<Point> getHermitCurve(const std::vector<Point>& controlPoints, const Color& color = BLACK);

  static std::vector<Point> getBesieCurve(const std::vector<Point>& controlPoints, const Color& color = BLACK);

  static std::vector<Point> getBSplineCurve(const std::vector<Point>& controlPoints, bool isClosed, const Color& color = BLACK);   
};