
#pragma once
#include <iostream>
using namespace std;
#include "Tile.h"
#ifndef TRIGGER_H
#define TRIGGER_H

class Trigger : public Tile
{
public:
  Trigger();
  virtual ~Trigger();
  Trigger(bool);

  void action(Adventure*, Maze);



private:

protected:

};
#endif