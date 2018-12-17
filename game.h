﻿#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector>
#include "skystar.h"
#include "player.h"
#include "enemy.h"
#include "explosion.h"
#include <memory>
namespace Ui {
  class Game;
}

class Game : public QWidget
{
  Q_OBJECT
private:
  Ui::Game *ui;
  Player* player;
  //Player* player;
  QVector<std::shared_ptr<SkyStar>> sky;
  QVector<std::shared_ptr<Enemy>> enemies;
  QVector<std::shared_ptr<Explosion>> explosions;
public:
  explicit Game(QWidget *parent = nullptr);
  void paintEvent(QPaintEvent *event);
  void keyPressEvent(QKeyEvent *event);
  void keyReleaseEvent(QKeyEvent *event);
  ~Game();

  bool loadGame();
  bool saveGame() const;
  void newGame();
  void read(const QJsonObject &json);
  void write(QJsonObject &json) const;

};

#endif // GAME_H
