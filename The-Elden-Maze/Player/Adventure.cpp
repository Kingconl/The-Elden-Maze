#include <iostream>
#include "Adventure.h"

#include "../Maze.h"
#include "../Getch.h"
#include "../Tile/Water.h"
#include "../Tile/Canister.h"
#include "../Tile/Trigger.h"
#include "../Tile/Tile.h"
#include "../Tile/Free.h"
#include "../Tile/Trap.h"
using namespace std;

Adventure::Adventure()
{
    waterLeft = 15;
    waterMax = 30;
    walls_Broken = 0;//defult starts with half max water
}

Adventure:: ~Adventure()
{
    //dtor
}

void Adventure::move(Maze maze)
{
    Getch input;//mostly same thing as player movement 

    cout << "Move input:";

    char movement = input.pause();
    cout << endl;
    int pX = x;
    int pY = y;

    if (movement == 'w')
    {
        pY = y - 1;
    }
    else if (movement == 's')
    {
        pY = y + 1;
    }
    else if (movement == 'a')
    {
        pX = x - 1;
    }
    else if (movement == 'd')
    {
        pX = x + 1;
    }
    else{
        return;
    }

    if (pX > 29 || pX < 0 || pY > 19 || pY < 0 || maze.layout[pY][pX]->getFree() == false)
    {
        return;
    }

    maze.layout[y][x]->setPlayer(false);
    maze.layout[pY][pX]->setPlayer(true);
    y = pY;
    x = pX;
    waterLeft--;//if we move, lower water



    if (waterLeft == 0)
    {
        dead(maze, "dehydration.");//if water reaches 0, die
    }
    
    maze.layout[y][x]->action(this, maze);//runs whatever the tile's action

    return;
}

void Adventure::dead(Maze maze, string message)
{
    Getch g;
    
    cout << "\033[1m\033[31m" << "You Died from " << message << endl;
    
    cout << "Press any key to continue" << endl;
    g.pause();
    
    maze.layout[6][1]->setIcon("\033[1m\033[33m" "█");
    maze.layout[6][1]->setFree(false);
    maze.layout[1][3]->setIcon("\033[1m\033[33m" "█");
    maze.layout[1][3]->setFree(false);
    maze.layout[6][0]->setBreadcrums(false);
    maze.layout[2][11]->setIcon("\033[1m\033[33m" "█");
    maze.layout[2][11]->setFree(false);
    maze.layout[1][10]->setBreadcrums(false);
    maze.layout[15][29]->setIcon("\033[1m\033[33m" "█");
    maze.layout[15][29]->setFree(false);
    maze.layout[19][15]->setBreadcrums(false);

    walls_Broken = 0;
    
    maze.layout[y][x]->setPlayer(false);//sets player back to start
    maze.layout[0][0]->setPlayer(true);
    x = 0;
    y = 0;
    
    waterLeft = waterMax / 2;
    return;
}

void Adventure::tick()
{    
    Getch g;
    Tile* layout[20][30] =
      {
      {new Tile("\033[1m\033[31m" " ", true, true), new Free(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free()},
      {new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Trigger(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Free()},
      {new Free(), new Tile(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Trap(), new Tile() , new Free(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Free()},
      {new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Free()},
      {new Free(), new Water(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Water(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free()},
      {new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free()},
      {new Trigger(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile()},
      {new Tile(), new Water(), new Free(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Water(), new Free(), new Free()},
      {new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile()},
      {new Canister(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile()},
      {new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Tile()},
      {new Free(), new Tile(), new Free(), new Free(), new Free(), new Trap(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile()},
      {new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile()},
      {new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Trap("\033[1m\033[36m" "C"), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile()},
      {new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Free()},
      {new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile()},
      {new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free()},
      {new Free(), new Free(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Tile(), new Free(), new Tile(), new Free(), new Tile(), new Free(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Free()},
      {new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Water(), new Tile(), new Free(), new Free(), new Free(), new Trap("\033[1m\033[37m" "L"), new Tile(), new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Tile(), new Tile(), new Trap()},
      {new Free(), new Free(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Trigger(), new Free(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Tile(), new Free(), new Free(), new Free(), new Tile("\033[1m\033[31m" "⚑", true, false)}
      };
    
    Maze maze(layout);
    
    intro();
    
    g.pause();
    
    (void)system("clear");
    cout << "\033[1m\033[34m" "Water: "<< waterLeft << "/" << waterMax <<endl;
    maze.fowDisplay(this->getX(), this->getY());

    do {
        move(maze);
         (void)system("clear");
        cout << "\033[1m\033[34m" "Water: "<< waterLeft << "/" << waterMax << endl;
        maze.fowDisplay(this->getX(), this->getY());

    } while (x != 29 or y != 19);
 
 cout << "You won!!" << endl << "Press any key to celebrate!";
    g.pause();
    x = 0;//resets coords
    y = 0;
    for(int i = 0; i <20; i++)
        {//frees memery
            for(int j = 0; j<30; j++)
                {

                    delete layout[i][j];

                }
        }
    return;
}

void Adventure::intro()
{
    cout << "The fallen leaves tell a story. The great Elden Ring was shattered. In our home, across the fog, the Lands Between. Now, Queen Marika the Eternal is nowhere to be found, and in the Night of the Black Knives, Godwyn the Golden was the first to perish. Soon, Marika's offspring, demigods all, claimed the shards of the Elden Ring. The mad taint of their newfound strength triggered the Shattering. A war from which no lord arose. A war leading to abandonment by the Greater Will. Arise now, ye Tarnished. Ye dead, who yet live. The call of long-lost grace speaks to us all. Hoarah Loux, chieftan of the badlands. The ever-brilliant Goldmask. Fia, the Deathbed Companion. The loathsome Dung Eater. And Sir Gideon Ofnir, the All-knowing. And one other. Whom grace would again bless. A Tarnished of no renown. Cross the fog, to the Lands Between. To stand before the Elden Ring. And become the Elden Lord." << endl << endl << "You wake up in a maze prepared to become the next elden lord, but you choose the wrong chacter! You realize when you cant see that you selected Hyetta! Your water supply is running out, so you better hurry and find those Shabiris Grapes" << endl << "Legend: " << endl << " W: Refills water supply\n C: Upgrades maximum water limit \n L: Mysterious Lever\n CAREFULL there may a couple hidden trap or 2. They may be camouflaged.\n ⚑: Finish Line."<< endl << "Press any key to continue";
    
    return;
}


int Adventure::getWaterLeft() const
{
    return waterLeft;
}

void Adventure::setWaterLeft(int _waterLeft)
{
    waterLeft = _waterLeft;
    return;
}

int Adventure::getWaterMax() const
{
    return waterMax;
}

void Adventure::setWaterMax(int _waterMax)
{
    waterMax = _waterMax;
    return;
}




void Adventure::setWalls_Broken(int _walls_Broken)
{
    walls_Broken = _walls_Broken;
    return;
}
int Adventure::getWalls_Broken()
{
    return walls_Broken;
}




void Adventure::setY(int _y)
{
    y = _y;
    return;
}
int Adventure::getY() const
{
    return y;
}



void Adventure::setX(int _x)
{
    x = _x;
    return;
}
int Adventure::getX() const
{
    return x;
}


