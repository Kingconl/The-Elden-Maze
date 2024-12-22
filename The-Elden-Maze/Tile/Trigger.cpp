#include <iostream>
#include "Trigger.h"
#include "../Maze.h"

using namespace std;

Trigger::Trigger()
{
  free = true;
  icon = "\033[1m\033[37m" "L";

}

Trigger::~Trigger()
{
  //dtor
}
Trigger::Trigger(bool _player)
{
  free = true;
  icon = "\033[1m\033[37m" "L";
  player = _player;
  breadcrums = false;
}

void Trigger::action(Adventure* player, Maze maze)
{
  Getch g;
  cout << "You Pushed a lever!" << endl;
  if (breadcrums)
  {//we use breadcrums to track if the lever has been used
    cout << "Nothing happened" << endl;
    cout << "Press any key to continue" << endl;
    g.pause();
    return;
  }

  switch(player->getWalls_Broken()) {
    case 0://since only 1 lever is accessible, i track walls broken to know which one to use
      cout << "Something moved!" << endl;
      maze.layout[6][1]->setIcon(" ");
      maze.layout[6][1]->setFree(true);
      maze.layout[1][3]->setIcon(" ");
      maze.layout[1][3]->setFree(true);
    break;
    case 1:
      cout << "Something moved!" << endl;
      maze.layout[2][11]->setIcon(" ");
      maze.layout[2][11]->setFree(true);
    break;
    case 2:
      cout << "Something moved!" << endl;
      maze.layout[15][29]->setIcon(" ");
      maze.layout[15][29]->setFree(true);
    break;

  }
  player->setWalls_Broken(player->getWalls_Broken() + 1);
  breadcrums = true;
  cout << "Press any key to continue" << endl;
 g.pause();
  return;
}

