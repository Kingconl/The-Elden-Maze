#pragma once
#include <iostream>
using namespace std;
#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "Player.h"

class Maze;

class Adventure : protected Player
{
public:
  Adventure();
  virtual ~Adventure();
  void move(Maze);
  void tick();
  void intro();
  void dead(Maze, string);
  int getWaterLeft() const;
  int getWaterMax() const;
  void setWaterLeft(int);
  void setWaterMax(int);
  void setWalls_Broken(int);
  int getWalls_Broken();
  void setY(int);

  int getY() const;
  void setX(int);
  int getX() const;
private:

  int waterLeft;
  int waterMax;
  int walls_Broken;

protected:


};
#endif