#include <iostream>
#include "Maze.h"
using namespace std;

Maze::Maze()
{
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 30; x++)
        {
            layout[y][x] = nullptr;
        }
    }

}

Maze::Maze(Tile* _layout[20][30])
{
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 30; x++)
        {
            layout[y][x] = _layout[y][x];
        }
    }

}

Maze:: ~Maze()
{
    //dtor
}

void Maze::setLayout(Tile* _layout[20][30])
{
    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 30; x++)
        {
            layout[y][x] = _layout[y][x];
        }
    }
}

void Maze::display()
{//using replit with linex so no access to cursor
  (void)system("clear");

    cout << "\033[1m\033[37m""--------------------------------" << endl;
    for (int y = 0; y < 20; y++)
    {
        cout << "\033[1m\033[37m""|";
        for (int x = 0; x < 30; x++)
        {
            cout << (layout[y][x])->getIcon();
        }
        cout << "\033[1m\033[37m""|" << endl;
    }
    cout << "\033[1m\033[37m""--------------------------------" << endl;
    return;
}

void Maze::fowDisplay(int x, int y)
{
//only displays the tiles you can see + the tiles adjectent to them
    int c = 0;

    layout[y][x]->setVision(true);

    while ((y - c-1) > -1 && (y - c - 1) <20 && c <= 4)
    {
        layout[y-c-1][x]->setVision(true);
        if (layout[y - c - 1][x]->getFree() == false)
        {
            c = 5;
        }
        if ((x-1) > - 1 && (x - 1) <30 && c <= 4)
        {
           layout[y - c - 1][x-1]->setVision(true);
        }
        if ((x + 1) > -1 && (x + 1) < 30 && c <= 4)
        {
            layout[y - c - 1][x+1]->setVision(true);
        }

        c++;
    }
    c = 0;


    while ((y + c +1) > -1 && (y + c +1) < 20 && c <= 4)
    {
        layout[y + c + 1][x]->setVision(true);
        if (layout[y + c + 1][x]->getFree() == false)
        {
            c = 5;
        }
        if ((x - 1) > -1 && (x - 1) < 30 && c <= 4)
        {


            layout[y + c + 1][x - 1]->setVision(true);


        }
        if ((x + 1) > -1 && (x + 1) < 30 && c <= 4)
        {

            layout[y + c + 1][x + 1]->setVision(true);


        }

        c++;
    }
    c = 0;


    while ((x + c + 1) > -1 && (x + c + 1) < 30 && c <= 4)
    {
        layout[y][x+c+1]->setVision(true);
        if (layout[y][x + c + 1]->getFree() == false)
        {
            c = 5;
        }
        if ((y - 1) > -1 && (y - 1) < 20 && c <= 4)
        {
            layout[y -1][x + c +1]->setVision(true);
        }
        if ((y + 1) > -1 && (y + 1) < 20 && c <= 4)
        {
            layout[y +1][x + c + 1]->setVision(true);
        }

        c++;
    }
    c = 0;
    while ((x - c - 1) > -1 && (x - c - 1) < 30 && c <= 4)
    {
        layout[y][x - c - 1]->setVision(true);

        if (layout[y][x - c - 1]->getFree() == false)
        {
            c = 5;
        }

        if ((y - 1) > -1 && (y - 1) < 20 && c <= 4)
        {
            layout[y - 1][x - c - 1]->setVision(true);
        }
        if ((y + 1) > -1 && (y + 1) < 20 && c <= 4)
        {
            layout[y + 1][x - c - 1]->setVision(true);
        }

        c++;
    }
    c = 0;
    cout << "\033[1m\033[37m" "--------------------------------" << endl;
    for (int y = 0; y < 20; y++)
    {
        cout << "\033[1m\033[37m" "|";
        for (int x = 0; x < 30; x++)
        {
            if (layout[y][x]->getVision())
            {
                cout << (layout[y][x])->getIcon();
            }
            else
            {
                cout << "\033[1m\033[30m" << "?";
            }
        }
        cout <<"\033[1m\033[37m" "|" << endl;
    }
    cout <<"\033[1m\033[37m" "--------------------------------" << endl;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            layout[i][j]->setVision(false);
        }
    }


    return;
}

