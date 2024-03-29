﻿#ifndef EXPLOSIONFIRE_H
#define EXPLOSIONFIRE_H

#include"gameobject.h"
#include"animated.h"

class Explosion : public GameObject
{
public:
  Explosion(QPoint point);
  void animate(Animated::Animation type);
  static bool makeFramesFromPixmap();
  void draw(std::shared_ptr<QPainter> painter) final override;
  void move() final override;
  void reuse(QPoint);

  void read(const QJsonObject &json) final override;
  void write(QJsonObject &json) const final override;
private:
  QPixmap* frame;
  static QVector<QPixmap*> frames;
  const bool helper = makeFramesFromPixmap();
};

#endif // EXPLOSIONFIRE_H
