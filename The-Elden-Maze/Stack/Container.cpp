#include <iostream>
using namespace std;
#include "Container.h"

Container::Container()
{
    contents = ' ';
}

Container::Container(char _contents, Container* _next)
{
    contents = _contents;
    next = _next;
}


Container:: ~Container()
{
  //dtor
}

Container* Container::getNext()
{
  return next;
}


char Container::getContents()
{
  return contents;
}



void Container::setNext(Container* _next)
{
  next = _next;
  return;
}


void Container::setContents(char _contents)
{
  contents = _contents;
  return;
}