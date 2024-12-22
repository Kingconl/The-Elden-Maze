#include <iostream>
#include <unistd.h>
using namespace std;
#include "Algorithm.h"
#include "../Tile/Tile.h"
#include "../Tile/Free.h"




Algorithm::Algorithm()/// wsad
{                     /// ad
    moves.setTop(nullptr);
    moves.push('d');
    moves.push('a');
    moves.push('s');
    moves.push('w');
}

Algorithm::~Algorithm()
{

}

void Algorithm::moveList(Maze maze)//Its the moves that the algortihm runs
{

    char aiMove = moves.getTop()->getContents();//more efficient
    if (aiMove == 'b')
    {

        moves.pop();


        move(maze, moves.getTop()->getContents(), true);//wsad : absadbs
        moves.pop();

        maze.display();
        usleep(300000);
        return;
    }

    if (move(maze, aiMove, false))
    {//push the right values

        moves.pop();
        if (aiMove == 'w')
        {

            
            moves.push('s');
            moves.push('b');
            moves.push('d');
            moves.push('a');
            moves.push('w');

            maze.display();
            usleep(300000);

            maze.layout[y][x]->setBreadcrums(true);//sets breadcrums
        }

        else if (aiMove == 's')
        {

            moves.push('w');
            moves.push('b');
            moves.push('d');
            moves.push('a');
            moves.push('s');

            maze.display();
            usleep(300000);

            maze.layout[y][x]->setBreadcrums(true);
        }

        else if (aiMove == 'a')
        {

            moves.push('d');
            moves.push('b');
            moves.push('a');
            moves.push('s');
            moves.push('w');
            
            maze.display();
            usleep(300000);

            maze.layout[y][x]->setBreadcrums(true);
        }

        else if (aiMove == 'd')
        {

            moves.push('a');
            moves.push('b');
            moves.push('d');
            moves.push('s');
            moves.push('w');
            maze.display();
            usleep(300000);

            maze.layout[y][x]->setBreadcrums(true);
        }
        return;
    }
    if (moves.getTop()->getContents() != 'b')//pops unless its a b, should only ever be b if loop is dectected
    {
        moves.pop();
    }
    return;
}




bool Algorithm::move(Maze maze, char movement, bool back)
{
    int pX = x;//potenialX
    int pY = y;//potenialY

    if (movement == 'w')//turns to potential new coords
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

    if (pX > 29 || pX < 0 || pY > 19 || pY < 0 || maze.layout[pY][pX]->getFree() == false)
    {
        return false;//it doesnt move so we dont push
    }
    else if (maze.layout[pY][pX]->getBreadcrums() && back == false)
    {//if we run into a tile with breadcrums, start backtracking and dont go foward thourgh breadcrums
        moves.pop();
        if (moves.getTop()->getContents() != 'b')
        {
            moves.push('b');
        }
        return false;
    }

    maze.layout[y][x]->setPlayer(false);
    maze.layout[pY][pX]->setPlayer(true);
    //maze.layout[pY][pX]->setBreadcrums(true);

    y = pY;
    x = pX;

    return true;//it moved so we do push
}

void Algorithm::tick()//runs the program
{
    Getch g;
    Tile * wall = new Tile();
      Tile* layout[20][30] =
      {//maze
    { new Tile("\033[1m\033[31m" " ", true, true), new Free(), new Free(), new Free(), new Free(), wall, wall, new Free(), wall, wall, wall, wall, wall, wall, wall, wall, new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, new Free() },
    { new Free(), wall, new Free(), wall, new Free(), new Free(), wall, new Free(), wall, wall, new Free(), new Free(), wall, wall, wall, wall, new Free(), new Free(), new Free(), wall, wall, wall, new Free(), new Free(), new Free(), wall, wall, wall, new Free(), new Free() },
    { new Free(), wall, new Free(), new Free(), wall, new Free(), wall, new Free(), wall, wall, wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), new Free(), new Free(), wall, new Free(), wall, wall, wall, new Free(), new Free() },
    { new Free(), wall, wall, wall, wall, new Free(), wall, new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, new Free(), wall, wall, new Free(), wall, wall, new Free(), wall, new Free(), new Free(), new Free(), new Free() },
    { new Free(), new Free(), wall, wall, wall, new Free(), wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, wall, new Free() },
    { wall, wall, wall, wall, wall, new Free(), new Free(), wall, wall, wall, new Free(), wall, wall, wall, wall, wall, wall, new Free(), wall, new Free(), wall, new Free(), wall, new Free(), new Free(), wall, new Free(), wall, wall, new Free() },
    { new Free(), new Free(), wall, wall, wall, wall, new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), new Free(), new Free(), wall, wall, new Free(), wall, new Free(), new Free(), new Free(), wall, new Free(), wall, wall, new Free(), wall, wall, wall },
    { wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, wall, wall, new Free(), wall, wall, new Free(), new Free(), new Free(), new Free() },
    { wall, wall, wall, wall, wall, wall, wall, wall, new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, new Free(), new Free(), new Free(), wall, wall, wall, wall, new Free(), wall },
    { new Free(), new Free(), wall, wall, new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), wall, new Free(), new Free(), new Free(), wall, new Free(), new Free(), wall, new Free(), wall, new Free(), wall, wall, wall, wall, wall, wall, new Free(), wall },
    { new Free(), wall, wall, wall, new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, wall, wall, wall, wall, new Free(), wall, new Free(), wall, wall, wall, new Free(), new Free(), new Free(), new Free(), wall },
    { new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, wall, new Free(), new Free(), new Free(), new Free(), wall, wall, new Free(), wall, new Free(), new Free(), new Free(), new Free(), new Free(), wall, wall, wall, wall },
    { new Free(), new Free(), wall, wall, wall, wall, new Free(), wall, new Free(), wall, new Free(), new Free(), wall, wall, wall, wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, wall, wall, new Free(), wall, wall, wall, wall },
    { new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, wall, new Free(), new Free(), new Free(), new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, wall, wall, new Free(), wall, wall, wall, wall },
    { new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, wall, new Free(), new Free(), new Free(), wall, wall, new Free(), wall, wall, wall, wall, wall, new Free(), new Free(), new Free(), new Free(), new Free() },
    { new Free(), new Free(), new Free(), wall, new Free(), wall, new Free(), new Free(), new Free(), wall, wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), new Free(), new Free(), new Free(), new Free(), wall, wall, wall, wall },
    { new Free(), new Free(), new Free(), wall, new Free(), wall, wall, wall, wall, new Free(), new Free(), new Free(), wall, wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, wall, wall, wall, wall, new Free(), new Free(), new Free(), new Free(), new Free() },
    { new Free(), new Free(), new Free(), wall, new Free(), wall, wall, wall, wall, new Free(), wall, new Free(), wall, wall, new Free(), wall, new Free(), wall, new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, wall, wall, wall, wall, new Free() },
    { new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), new Free(), wall, new Free(), new Free(), new Free(), new Free(), wall, new Free(), new Free(), new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, new Free() },
    { new Free(), new Free(), new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, new Free(), new Free(), wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, new Tile("\033[1m\033[31m" "⚑", true, false) }
      };
    Maze maze(layout);
    maze.display();
    usleep(300000);
    do {
        moveList(maze);
        //usleep(10000000);

    } while (x != 29 or y != 19);
    cout << "You won!!" << endl << "Press any key to celebrate!";
    g.pause();
    x = 0;
    y = 0;//resets
    for(int i = 0; i <20; i++)
        {
            for(int j = 0; j<30; j++)
                {
                    if(layout[i][j] != wall)
                    {
                        delete layout[i][j];
                    }
                }
        } //Since when it returns, the class should close. So we prevent memory leaks. 
    delete wall;
    return;
}


/*void Algorithm::moveList2(Maze maze)//dasw
{
  cout << "MOVE LIST 2 STARTED!!!!!!!!!!!!!!!!!!" << endl;
  bool test = false;
  int oldX = x;
  int oldY = y;
  string aiMove = "";
  do{
    cout << "doaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl << "TOP IS: " <<  moves.getTop()->getContents() << endl;
   aiMove = moves.getTop()->getContents();//more efficient
    if (aiMove == 'b')
    {

         moves.pop();


      move(maze, moves.getTop()->getContents());//wsad : absadbs
       moves.pop();

      maze.display();
      Sleep(200);

    }

  if(move(maze, aiMove) && aiMove != 'b')
  {
    moves.pop();
    if(aiMove == 'w')
    {
      moves.push('s');
      moves.push('w');
      moves.push("b");
      moves.push('a');
      moves.push('d');
      if((maze.layout[y][x]->getBreadcrums() == false) or (oldY == y && oldX == x))
        {
        cout << "MOVE LIST 2 ENDED:(:(:(" << endl;
        return;
        }
      maze.display();
      Sleep(200);
       maze.layout[y][x]->setBreadcrums(true);
    }
    else if(aiMove == 's')
      {

        moves.push('w');
        moves.push('s');
        moves.push("b");
        moves.push('a');
        moves.push('d');

        maze.display();
        Sleep(200);
        if((maze.layout[y][x]->getBreadcrums() == false) or (oldY == y && oldX == x))
          {
          cout << "MOVE LIST 2 ENDED:(:(:(" << endl;
          return;
          }
         maze.layout[y][x]->setBreadcrums(true);
      }

    else if(aiMove == 'a')
      {

        moves.push('d');
        moves.push('s');
        moves.push("b");
        moves.push('w');
        moves.push('a');
        if((maze.layout[y][x]->getBreadcrums() == false) or (oldY == y && oldX == x))
          {
          cout << "MOVE LIST 2 ENDED:(:(:(" << endl;
          return;
          }
        maze.display();
        Sleep(200);
         maze.layout[y][x]->setBreadcrums(true);
      }

    else if(aiMove == 'd')
      {

        moves.push('a');
        moves.push('s');
        moves.push("b");
        moves.push('w');
        moves.push('d');
        if((maze.layout[y][x]->getBreadcrums() == false) or (oldY == y && oldX == x))
          {
          cout << "MOVE LIST 2 ENDED:(:(:(" << endl;
          return;
          }
        maze.display();
        Sleep(200);
         maze.layout[y][x]->setBreadcrums(true);
      }

  }
    else if(aiMove != "b")
  {
    cout << "outside pop" << endl;
    moves.pop();
  }
  }while(test == false);

  return;
  }
*/