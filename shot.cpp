﻿#include "shot.h"
#include "gameobject.h"
#include<iostream>
#include"shotpool.h"
Shot::Shot(QRect rect, GameObject::Type type)
{
  this->gameObjectType = type;
  this->rect = rect;
  pixmap = QPixmap(":/images/images/PlayerShotSprite.png");
  if(type == GameObject::Type::EnemyShot){
      pixmap = QPixmap(":/images/images/EnemyShotSprite.png");
      speed = 15;
    }else{
      speed = -20;
    }
}

void Shot::move()
{
  rect = QRect(rect.left(),rect.top()+qRound(speed),rect.width(),rect.height());
  if (rect.y() < -50 || rect.y() > 850){
      this->hurt();
    }
}

void Shot::reuse(QPoint point)
{
  this->rect = QRect(point,QSize(6,12));
  lives = 1;
}

