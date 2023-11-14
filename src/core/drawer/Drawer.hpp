#pragma once

#include "core/point/Point.hpp"
#include <vector>


class Drawer {
public:
  static PointVector getDDALine(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static PointVector getBresenhemLine(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static PointVector getWuLine(const Point& startPoint, const Point& endPoint, const Color& color = BLACK);

  static PointVector getCircle(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color = BLACK);

  static PointVector getEllipse(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color = BLACK);

  static PointVector getHyperbola(const Point& startPoint, const Point& endPoint, const Point& maxPoint, bool isHorizontal = true, const Color& color = BLACK);

  static PointVector getParabola(const Point& startPoint, const Point& endPoint, const Point& maxPoint, const Color& color = BLACK);

  static PointVector getHermitCurve(const PointVector& controlPoints, const Color& color = BLACK);

  static PointVector getBesieCurve(const PointVector& controlPoints, const Color& color = BLACK);

  static PointVector getBSplineCurve(const PointVector& controlPoints, bool isClosed, const Color& color = BLACK);   
};