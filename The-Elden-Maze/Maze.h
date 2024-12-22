#include <iostream>

#include "Tile/Tile.h"
using namespace std;
#ifndef MAZE_H
#define MAZE_H

class Maze
{
public:
  Maze();
  virtual ~Maze();
  Maze(Tile* [20][30]);
  /*Tile * layout [10][20] =
  {
  {new Free(true), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), new Free(), new Free(), wall, wall, new Free(), new Free(), new Free() },
  {new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, new Free(), new Free(), new Free(), wall, new Free(), new Free(), new Free(), new Free(), wall, new Free()},
  {new Free(), wall, wall, wall, wall, new Free(), new Free(), new Free(), new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, new Free() },
  {new Free(), wall, new Free(), new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), new Free(), new Free(), new Free(), wall, wall, wall, wall, wall, new Free()},
  {wall, wall, new Free(), new Free(), wall, new Free(), wall, wall, new Free(), new Free(), new Free(), wall, wall, new Free(), wall, wall, wall, wall, wall, new Free()},
  {new Free(), new Free(), new Free(), new Free(), wall, new Free(), wall, wall, wall, wall, new Free(), wall, wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free()},
  {new Free(), wall, new Free(), new Free(), wall, new Free(), wall, new Free(), new Free(), wall, new Free(), wall, wall, new Free(), wall, wall, wall, wall, wall, wall},
  {new Free(), wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), new Free(), new Free(), new Free(), wall, wall, wall, wall, wall, wall},
  {new Free(), wall, wall, wall, wall, wall, new Free(), wall, new Free(), new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free()}

  };*/
  void setLayout(Tile * [20][30]);

  Tile* layout[20][30];
  /*
   Tile * layout [20][30] =
  {
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall},
  {wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall}
  };*/
  /*
   Tile * layout [20][30] =
  {
  {Free, Free, Free, Free, Free, wall, wall, Free, wall, wall, wall, wall, wall, wall, wall, wall, Free, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, Free},
  {Free, wall, Free, wall, Free, Free, wall, Free, wall, wall, Free, Free, wall, wall, wall, wall, Free, Free, Free, wall, wall, wall, Free, Free, Free, wall, wall, wall, Free, Free},
  {Free, wall, Free, Free, wall, Free, wall, Free, wall, wall, wall, Free, Free, Free, Free, Free, Free, wall, Free, wall, Free, Free, Free, wall, Free, wall, wall, wall, Free, Free},
  {Free, wall, wall, wall, wall, Free, wall, Free, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, Free, wall, wall, Free, wall, wall, Free, wall, Free, Free, Free, Free},
  {Free, Free, wall, wall, wall, Free, wall, Free, Free, Free, Free, Free, Free, Free, Free, Free, Free, Free, Free, Free, wall, Free, wall, wall, Free, wall, Free, wall, wall, Free},
  {wall, wall, wall, wall, wall, Free, Free, wall, wall, wall, Free, wall, wall, wall, wall, wall, wall, Free, wall, Free, wall, Free, wall, Free, Free, wall, Free, wall, wall, Free},
  {Free, Free, wall, wall, wall, wall, Free, Free, Free, wall, Free, wall, Free, Free, Free, wall, wall, Free, wall, Free, Free, Free, wall, Free, wall, wall, Free, wall, wall, wall},
  {wall, Free, Free, Free, Free, Free, Free, wall, Free, wall, Free, wall, Free, wall, Free, wall, wall, Free, wall, Free, wall, wall, wall, Free, wall, wall, Free, Free, Free, Free},
  {wall, Wall, wall, wall, wall, wall, wall, wall, Free, wall, Free, wall, Free, wall, Free, wall, wall, Free, wall, Free, wall, Free, Free, Free, wall, wall, wall, wall, Free, wall},
  {Free, Free, wall, wall, Free, Free, Free, wall, Free, wall, Free, wall, Free, Free, Free, wall, Free, Free, wall, Free, wall, Free, wall, wall, wall, wall, wall, wall, Free, wall},
  {Free, wall, wall, wall, Free, wall, Free, wall, Free, wall, Free, wall, wall, Free, wall, wall, wall, wall, wall, Free, wall, Free, wall, wall, wall, Free, Free, Free, Free, wall},
  {Free, Free, Free, Free, Free, wall, Free, wall, Free, wall, Free, wall, wall, Free, Free, Free, Free, wall, wall, Free, wall, Free, Free, Free, Free, Free, wall, wall, wall, wall},
  {Free, Free, wall, wall, wall, wall, Free, wall, Free, wall, Free, Free, wall, wall, wall, wall, Free, wall, wall, Free, wall, Free, wall, wall, wall, Free, wall, wall, wall, wall},
  {Free, Free, Free, wall, Free, wall, Free, wall, Free, wall, wall, Free, Free, Free, Free, wall, Free, wall, wall, Free, wall, Free, wall, wall, wall, Free, wall, wall, wall, wall},
  {Free, Free, Free, wall, Free, wall, Free, wall, Free, wall, wall, Free, wall, wall, Free, Free, Free, wall, wall, Free, wall, wall, wall, wall, wall, Free, Free, Free, Free, Free},
  {Free, Free, Free, wall, Free, wall, Free, Free, Free, wall, wall, Free, wall, wall, Free, wall, Free, wall, wall, Free, wall, Free, Free, Free, Free, Free, wall, wall, wall, wall},
  {Free, Free, Free, wall, Free, wall, wall, wall, wall, Free, Free, Free, wall, wall, Free, wall, Free, wall, wall, Free, wall, wall, wall, wall, wall, Free, Free, Free, Free, Free},
  {Free, Free, Free, wall, Free, wall, wall, wall, wall, Free, wall, Free, wall, wall, Free, wall, Free, wall, Free, Free, Free, Free, Free, Free, wall, wall, wall, wall, wall, Free},
  {Free, Free, Free, Free, Free, Free, Free, Free, Free, Free, wall, Free, Free, Free, Free, wall, Free, Free, Free, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, Free},
  {Free, Free, Free, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, Free, Free, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, Free}
  };*/



  void display();
  void fowDisplay(int, int);

private:

protected:


};
#endif