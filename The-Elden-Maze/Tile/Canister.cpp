#include <iostream>
#include "Canister.h"
#include "../Maze.h"

using namespace std;

Canister::Canister()
{
  free = true;
  icon = "\033[1m\033[36m" "C";

}

Canister:: ~Canister()
{
  //dtor
}


void Canister::action(Adventure* player, Maze maze)
{
  Getch g;
  if(maze.layout[player->getY()][player->getX()]->getBreadcrums() == false)//I used breadcrums to know if the canisters been used before
  {
    player->setWaterMax(50);

    maze.layout[player->getY()][player->getX()]->setIcon(" ");//looks normal
    cout << "You picked up a magic canister that will stay after death. Your maximum water limit has been permanently increased." << endl;
    cout << "Press any key to continue" << endl;
     g.pause();
    maze.layout[player->getY()][player->getX()]->setBreadcrums(true);
  }

  return;
}

