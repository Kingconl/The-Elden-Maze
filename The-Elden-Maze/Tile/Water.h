#pragma once
#include <iostream>
using namespace std;
#include "Tile.h"
#ifndef WATER_H
#define WATER_H

class Water : public Tile
{
public:
  Water();
  virtual ~Water();

  void action(Adventure*, Maze);



private:

protected:

};
#endif