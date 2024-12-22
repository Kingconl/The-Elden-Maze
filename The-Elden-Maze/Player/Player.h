#pragma once
#include <iostream>
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
class Maze;


class Player
{
public:
  Player();
  virtual ~Player();
  void move(Maze);
  void tick();
  void intro();

private:

protected:
  int x;
  int y;


};
#endif