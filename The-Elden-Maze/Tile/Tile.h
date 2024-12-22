#pragma once
#include <iostream>
using namespace std;
#include "../Player/Adventure.h"
#include "../Getch.h"
class Maze;
#ifndef TILE_H
#define TILE_H

class Tile
{
public:
  Tile();
  virtual ~Tile();
  Tile(string, bool, bool);
  virtual void action(Adventure*, Maze);

  string getIcon();
  bool getFree() const;
  void setPlayer(bool);
  void setBreadcrums(bool);
  bool getBreadcrums() const;
  void setIcon(string);
  void setFree(bool);
  bool getVision();
  void setVision(bool);


private:

protected:
  bool player;
  bool breadcrums;
  string icon;
  bool free;
  bool vision;


};
#endif