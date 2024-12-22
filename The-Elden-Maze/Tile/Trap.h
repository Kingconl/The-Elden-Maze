#pragma once
#include <iostream>
using namespace std;
#include "Tile.h"
#ifndef TRAP_H
#define TRAP_H

class Trap : public Tile
{
public:
  Trap();
  virtual ~Trap();
  Trap(string);

  void action(Adventure*, Maze);



private:

protected:

};
#endif