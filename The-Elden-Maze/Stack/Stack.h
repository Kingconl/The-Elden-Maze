#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H
#include "Container.h"



class Stack

{   private:

        Container *top;



    public:

        Stack();

        Stack(Container*);

        virtual ~Stack();



        Container * getTop();

        void setTop(Container *);



        void pop();
        char peakContent();
        void push(char);

};
#endif