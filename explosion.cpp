#include "explosion.h"

QVector<QPixmap*> Explosion::frames;

Explosion::Explosion(QPoint point)
{
  gameObjectType = GameObject::Type::Asteroid;
  rect  = QRect(point.x(),point.y(),100,100);
  frame = frames.first();
  lives = 1;
}

bool Explosion::makeFramesFromPixmap(){
  if(frames.isEmpty()){
      static const QPixmap pixmap(":/images/images/explosionAsteroid.png");
      for(int i=0; i<32;i++){
          frames.push_back(new QPixmap(pixmap.copy(i*62,0,62,62)));
        }
    }
  return true;
}

void Explosion::animate(Animated::Animation type){
  if(frame != frames.last()){
      frame = frames[frames.indexOf(frame)+1];
    }else{
      frame = frames.first();
    }
  hurt();
}

void Explosion::reuse(QPoint point){
rect  = QRect(point.x(),point.y(),100,100);
frame = frames.first();
lives = 32;
}

void Explosion::draw(std::shared_ptr<QPainter> painter)
{
  painter->drawPixmap(rect,*frame);
}

void Explosion::read(const QJsonObject &json)
{

}

void Explosion::write(QJsonObject &json) const
{


}

void Explosion::move()
{


}

