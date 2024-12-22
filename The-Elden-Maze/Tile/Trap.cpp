#include <iostream>
#include "Trap.h"
#include "../Maze.h"

using namespace std;

Trap::Trap()
{
  free = true;
  icon = "\033[1m\033[34m" " ";

}

Trap:: ~Trap()
{
  //dtor
}


Trap::Trap(string _icon)
{
    free = true;
    icon = _icon;
    player = false;
    breadcrums = false;
    vision = false;
}

void Trap::action(Adventure* player, Maze maze)
{//kills the player if they step on it
  player->dead(maze, "stepping on trap.;(");

  return;
}