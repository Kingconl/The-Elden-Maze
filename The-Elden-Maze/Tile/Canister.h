#pragma once
#include <iostream>
using namespace std;
#include "Tile.h"
#ifndef CANISTER_H
#define CANISTER_H

class Canister : public Tile
{
public:
  Canister();
  virtual ~Canister();

  void action(Adventure*, Maze);

private:

protected:

};
#endif