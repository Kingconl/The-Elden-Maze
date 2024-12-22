#include <iostream>
using namespace std;
#include "Stack.h"

Stack::Stack()
{
  top = nullptr;
}

Stack::Stack(Container * _top)
{
  top = _top;
}


Stack:: ~Stack()
{
  //dtor
}
/*
string Stack::pop()

{   if (top != nullptr)

    {  Container * topContainer = top;

        top = top->getNext();

        topContainer->setNext(nullptr);

        string returnValue = topContainer->getContents( );

        delete topContainer;



        return returnValue;

    }
 return""; 
}*/

void Stack::pop()

{   if (top != nullptr)

    {  Container * topContainer = top;

        top = top->getNext();

        topContainer->setNext(nullptr);

        delete topContainer;



        return ;

    }
 return; 
}




void Stack::push(char _value)

{  
    Container * newContainer = new Container(_value, top);

    top = newContainer;



    return;

         }

Container* Stack::getTop()
{
    return top;
}

void Stack::setTop(Container* _top)
{
    top = _top;
  return;
}

char Stack::peakContent()
{
  return top->getContents();
}

