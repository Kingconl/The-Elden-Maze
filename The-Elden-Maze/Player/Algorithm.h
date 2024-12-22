#pragma once
#include <iostream>
using namespace std;
#ifndef AlGROITHM_H
#define AlGROITHM_H
#include "../Maze.h"
#include "Player.h"
#include "../Stack/Stack.h"



class Algorithm : protected Player
{
public:
  Algorithm();
  virtual ~Algorithm();
  bool move(Maze, char, bool);
  void tick();
  Stack moves;
  void moveList(Maze);
private:
  // Stack moves;

protected:



};
#endif