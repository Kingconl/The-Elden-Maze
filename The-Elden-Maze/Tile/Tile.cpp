#include <iostream>
#include "Tile.h"
#include "../Maze.h"
using namespace std;

Tile::Tile()
{
    free = false;
    icon = "\033[1m\033[33m" "█";
    player = false;
    breadcrums = false;
    vision = false;
}

Tile:: ~Tile()
{
    //dtor
}

Tile::Tile(string _icon, bool _free, bool _player)
{
    free = _free;
    icon = _icon;
    player = _player;
    breadcrums = false;
    vision = false;
}

void Tile::setIcon(string _icon)
{
    icon = _icon;
    return;
}

void Tile::setFree(bool _free)
{
    free = _free;
    return;
}

string Tile::getIcon()
{
    if (player == true)
    {
        return "\033[1m\033[32m" "P";
    }
    return icon;
}

void Tile::setPlayer(bool _player)
{
    player = _player;
    return;
}
bool Tile::getFree() const
{
    return free;
}

void Tile::setVision(bool _vision)
{
    vision = _vision;
    return;
}

bool Tile::getVision()
{
    return vision;
}


bool Tile::getBreadcrums() const 
{
    return breadcrums;
}

void Tile::setBreadcrums(bool _breadcrums)
{
    breadcrums = _breadcrums;
    return;
}


void Tile::action(Adventure* player, Maze maze)
{
    return;
}


