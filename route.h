﻿#ifndef ROUTE_H
#define ROUTE_H

#include <QPoint>
#include <QJsonObject>

class Route
{
public:
  enum class Path {Line, Stay, Left, Right, Bottom, None, Lemniscate, Sin, Top, HalfCircleRightLeft};

  explicit Route(class GameObject* object, Route::Path path, QPoint end);
  explicit Route(class GameObject* object,Route::Path path);
  Route() = default;
  virtual ~Route() = default;

  QPoint getNextPoint(double speed);
  Route::Path getRoutePath();
  bool isEnded();
  void setTheEnd(bool);
  void setStart();

  void read(const QJsonObject &json);
  void write(QJsonObject &json) const;
protected:
  QPoint start;
  QPoint end;
  Route::Path path;
private:
  QPoint position;
  double dx;
  double dy;
  double q;
  bool theEnd = false;
  class GameObject* parent;
};

#endif // ROUTE_H
