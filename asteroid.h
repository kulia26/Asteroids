#ifndef ASTEROID_H
#define ASTEROID_H
#include"physicalobject.h"

class Asteroid: public PhysicalObject
{
public:
  enum class Size{Big,Middle,Little};
  Asteroid(Size size, QPoint point);
  void move() final override;
  static void split(QPoint, Size size);
  Size getSize();
  void animate(Animated::Animation type);
  static bool makeFramesFromPixmap();
  void draw(std::shared_ptr<QPainter> painter) final override;
private:
  Size size;
  QPixmap* frame;
  int framesCount;
  static QVector<QPixmap*> frames;
  const bool helper = makeFramesFromPixmap();
  bool splited = false;
};

#endif // ASTEROID_H
