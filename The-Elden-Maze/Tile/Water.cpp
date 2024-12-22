#include <iostream>
#include "Water.h"
#include "../Maze.h"

using namespace std;

Water::Water()
{
  free = true;
  icon = "\033[1m\033[34m" "W";


}

Water:: ~Water()
{
  //dtor
}

void Water::action(Adventure* player, Maze maze)
{
  Getch g;
  player->setWaterLeft(player->getWaterMax());
  cout << "you refilled your water" << endl;
  cout << "Press any key to continue" << endl;
  g.pause();
  return;
}

