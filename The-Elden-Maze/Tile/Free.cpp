#include <iostream>
#include "Free.h"
using namespace std;

Free::Free()
{
  free = true;
  icon = "\033[1m\033[31m" " ";
}

Free:: ~Free()
{
  //dtor
}

Free::Free(bool _player)
{
  free = true;
  icon = "\033[1m\033[31m" " ";
  player = _player;
  breadcrums = false;
}