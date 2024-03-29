﻿#ifndef ENEMY_H
#define ENEMY_H

#include "gameobject.h"
#include "animated.h"
#include "shot.h"
#include "route.h"
#include <QVector>
#include <QPoint>
#include <memory>
#include "shooter.h"
#include "physicalobject.h"
#include "routed.h"

class Enemy : public PhysicalObject, protected Animated, public Shooter
{
public:
  enum class Type { Lobster, Fly, Wasp };
  explicit Enemy(Enemy::Type type, QPoint start,double speed);
  explicit Enemy();
  virtual ~Enemy() override;
  void move() final override;
  void animate(Animation type) final override;
  void makeFramesFromPixmap() final override;
  void fire() final override;//
  void draw(std::shared_ptr<QPainter> painter) final override;
  void attack(std::shared_ptr<GameObject> player);

  void read(const QJsonObject &json) final override;
  void write(QJsonObject &json) const final override;
private:
  Type type;
  bool canAttack;
};

#endif // ENEMY_H
