#include <iostream>
using namespace std;
#ifndef CONTAINER_H
#define CONTAINER_H

class Container

{   private:

        Container *next;

        char contents;



    public:

        Container();

        Container(char, Container*);



        virtual ~Container();



        Container* getNext();

        char getContents();



        void setNext(Container*);

        void setContents(char);

};
#endif