#include "asteroid.h"
#include "cmath"
#include "game.h"
#include <iostream>

QVector<QPixmap*> Asteroid::frames;
Asteroid::Asteroid(Size size, QPoint point)
{
  gameObjectType = GameObject::Type::Asteroid;
  speed = 2;
  this->size = size;
  rect  = QRect(point.x(),point.y(),100,100);
  if(size == Size::Big){
      rect  = QRect(point.x(),point.y(),300,300);
    }
  if(size == Size::Middle){
      rect  = QRect(point.x(),point.y(),150,150);
    }
  if(size == Size::Little){
      rect  = QRect(point.x(),point.y(),60,60);
    }
  pixmap = QPixmap(":/images/images/Asteroid.png");
  frame = frames.first();
  lives = 1;

}
bool Asteroid::makeFramesFromPixmap(){
  if(frames.isEmpty()){
      static const QPixmap pixmap(":/images/images/Asteroid.png");
      for(int i=0; i<72;i++){
          QTransform transform;
          QTransform trans = transform.rotate(5*i);
          QPixmap rotated = pixmap.transformed(trans);
          int xoffset = (rotated.width() - pixmap.width()) / 2;
          int yoffset = (rotated.height() - pixmap.height()) / 2;
          rotated = rotated.copy(xoffset, yoffset, pixmap.width(), pixmap.height());
          frames.push_back(new QPixmap(rotated));
        }
    }

  return true;
}

void Asteroid::move()
{
  rect.moveTo(currentRoute->getNextPoint(speed));
  animate(Animated::Animation::Rotate);
  if(currentRoute->isEnded()){
      if(rect.intersects(QRect(QPoint(350,900),QPoint(450,1100)))){
          hurt();
        }else{
          addRoute(Route::Path::Line, QPoint (400,1000));
          currentRoute = routes.last();
        }
    }

}
Asteroid::Size Asteroid::getSize()
{
return size;
}

void Asteroid::split(QPoint point, Size size)
{
      Size newSize = Size::Little;
      if(size == Size::Big){
          newSize = Size::Middle;

        }
      if(size == Size::Middle){
          newSize = Size::Little;
        }
      if(size == Size::Little){
          return;
        }
      for(int i = 0; i < 2; i++){
          int j = 1;
          if(i%2 == 0){
              j = -2;
            }
          std::shared_ptr<Asteroid> asteroid (new Asteroid(newSize, point + QPoint(j*10,-j*10)));
          asteroid->addRoute(Route::Path::Line, QPoint(Game::getInstance().getPlayer()->getPoint()+QPoint(j*100,0)));
          Game::getInstance().getAsteroids().push_back(asteroid);
          j++;
        }


}

void Asteroid::animate(Animated::Animation type){
  if(type == Animated::Animation::Rotate){
      if(frame != frames.last()){
          frame = frames[frames.indexOf(frame)+1];
        }else{
          frame = frames.first();
        }
  }
  framesCount++;
  if(framesCount > 10000){
      framesCount = 0;
  }
}

void Asteroid::draw(std::shared_ptr<QPainter> painter)
{
  painter->drawPixmap(rect,*frame);
}
