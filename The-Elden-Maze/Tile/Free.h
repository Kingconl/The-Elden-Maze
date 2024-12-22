#pragma once
#include <iostream>
using namespace std;
#include "Tile.h"
#ifndef FREE_H
#define FREE_H

class Free : public Tile
{
public:
  Free();
  virtual ~Free();
  Free(bool);



private:

protected:


};
#endif