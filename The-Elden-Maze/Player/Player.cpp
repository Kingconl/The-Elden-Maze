#include <iostream>
#include "Player.h"

#include "../Maze.h"
#include "../Getch.h"
#include "../Tile/Tile.h"
#include "../Tile/Free.h"

using namespace std;

Player::Player()
{
    x = 0;
    y = 0;
}

Player:: ~Player()
{
    //dtor
}

void Player::move(Maze maze)
{
   Getch input;
  
    cout << "Move input:";

    char movement = input.pause();
    cout << endl;
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
  else{
      return;
  }

    if (pX > 29 || pX < 0 || pY > 19 || pY < 0 || maze.layout[pY][pX]->getFree() == false)
    {
        return;//doesnt move
    }

    maze.layout[y][x]->setPlayer(false);//moves
    maze.layout[pY][pX]->setPlayer(true);

    y = pY;//sets y and x
    x = pX;



    return;
}

void Player::tick()//runs the maze
{  Getch g;

    Tile * wall = new Tile();
      Tile* layout[20][30] =
      {
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
    intro();
    g.pause();
    (void)system("clear");
    maze.display();
    do {
        move(maze);
        maze.display();
    } while (x != 29 or y != 19);
     cout << "You won!!" << endl << "Press any key to celebrate!";
     g.pause();
     x = 0;
     y = 0;
    for(int i = 0; i<20; i++)
        {//clears memory
            for(int j=0; j<30; j++)
                {
                    if(layout[i][j] != wall)
                    {
                        delete layout[i][j];
                    }
                }
        }
    delete wall;
    return;
}

void Player::intro()
{

    cout << "You find yourself stuck in a maze. Looking around, there are 0 maidens in the maze. Maybe if you choose the Tarnished route you would find a maiden." << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢮⠿⠧⠒⠚⠉⠋⢉⣀⣤⣾⣧⣢⢄⣀⠀⠀⢺⣶⡄⠉⠀⠀⢀⣀⠠⢁⡓⣬⢑⡾⢯⠹⡜⣿⣿⡝⣿⢋⡻⣿⣻⣟⣻⢿⣻⣟⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⡟⠛⣿⠛⢻⣿⡿⠛⠉⠛⢦⣄⢠⢤⣿⠓⠒⢻⡟⠛⠛⣿⣿⠛⠛⠛⣷⣾⡟⠛⣶⣿⠛⠛⠛⠻⣦⣷⠛⠛⠛⢷⣿⠛⢻⡟⠛⢿⣶⠟⠛⠙⠻⣾⣿⠞⠋⠛⠻⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⡇⠀⠹⠀⢸⣿⡇⠀⣿⠀⠀⡧⠡⣸⣿⠀⠀⢸⡇⠀⠀⣿⣿⠀⢀⠀⢻⣿⡇⠀⣿⣿⠀⢸⡇⠀⢸⣿⠀⠀⣷⣿⣿⠀⠀⢷⠀⣿⣿⠀⠹⣦⣤⣿⣿⣄⣸⠂⠀⣹⣿" << endl;
    cout << "⣿⣿⣿⣿⠀⠀⠀⠀⢸⣿⡇⠀⣿⠀⠀⣧⣷⣿⣿⠀⢸⠀⠀⡆⠀⣿⡏⠀⢸⠀⠸⣿⡇⠀⢾⣿⠀⢸⡇⠀⢸⢾⠀⢀⣈⣿⣿⠀⢀⠀⠀⣿⣿⣦⣀⠀⠙⣿⣿⠉⠙⠁⠀⣼⣿" << endl;
    cout << "⣿⣿⣿⣿⠀⠀⡆⠀⢸⣿⡇⠀⠿⡄⢀⣿⣿⢻⣷⠀⢸⡀⢀⡇⢀⣿⡇⠀⣠⡀⠀⣿⣇⠀⣻⣿⠀⠸⠇⠀⣸⣿⠀⠀⠿⢿⣿⠀⢸⡀⠀⢿⣿⠀⠸⠇⠀⣸⣿⠶⢾⣶⣾⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣶⣴⣿⣦⡼⠟⠛⢶⣤⣾⣿⣿⠏⣼⢿⢴⣾⣷⣾⣷⠶⠛⠳⠦⠟⠳⠶⠟⠳⠶⠟⠹⢶⣶⢾⣿⣿⡿⣷⣷⣦⡾⠻⠶⠼⠷⠶⠾⢿⣷⣤⡤⠾⠻⠻⠦⢾⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⠋⠀⢠⡖⣩⣾⣿⠟⡁⡾⠃⠀⣮⣿⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡸⣿⣿⣷⠀⢹⣮⣧⠀⠀⢣⡀⠀⢠⠈⢿⡧⣼⠁⡄⢣⠐⠀⢻⣿⣿⣾" << endl;
    cout << "⣿⣽⣿⣻⣿⡿⠁⠀⣴⢋⣼⣿⠿⠋⣰⠇⠀⢀⣶⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢷⢻⣻⢿⡄⠂⣽⣿⡄⡘⠌⢓⠀⠂⠐⠘⢿⣼⣷⢀⠈⡲⢦⣆⡿⣿⣿" << endl;
    cout << "⣿⢷⣯⣿⠟⠀⢀⡞⢡⣾⠟⠁⢠⣾⠏⠀⠀⣼⢿⣿⠇⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣾⡄⣿⡆⠐⡈⣿⡏⣑⠣⢌⠃⠀⠉⣤⣦⡉⢿⣿⣇⠺⣥⣞⡵⡹⣿" << endl;
    cout << "⡿⣯⣿⠋⢀⡴⣋⣴⠟⠁⠀⣰⣿⠏⢀⠀⣸⣯⣿⡟⠀⠀⠀⠀⡠⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣇⠸⣷⡐⡀⢹⣷⣌⢝⠢⢌⢠⡁⣹⣿⣧⠈⢿⣿⡳⡆⡝⣜⢡⢻" << endl;
    cout << "⢷⣿⢏⠀⡞⡼⠉⠁⡴⢫⣾⣿⡣⢰⠇⣀⣿⣿⣿⠃⠀⠀⠀⠀⠀⣠⣼⡇⠀⠀⠀⠀⠀⠀⠀⢀⣴⡖⠀⠳⢻⡀⢻⣷⠀⠀⠛⢾⣏⡝⢦⠀⡷⢸⣿⣿⠷⣮⣽⣷⣋⠖⡭⢦⣉" << endl;
    cout << "⣾⠏⣿⠀⠀⠀⢀⣾⣷⢟⢞⡽⣡⡿⣴⣿⣿⡟⠉⢀⣀⣠⣴⡾⠿⠿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⢻⣷⡄⠀⠈⢷⡘⣿⣯⠐⡈⠘⣿⡜⣯⡒⣿⡆⢻⣿⢯⢹⡿⣿⡗⣞⢰⠛⣶" << endl;
    cout << "⣿⢰⡇⠀⢀⢠⣿⡿⠋⢠⣾⢷⣿⣵⣿⣿⣿⠿⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠿⣶⣄⠀⠹⣇⠛⣷⡁⢀⢹⣿⡹⣷⣿⣏⠈⣿⣟⠦⣓⢿⣿⡌⢧⡋⠴" << endl;
    cout << "⣿⣿⡇⠐⢀⣾⡿⢃⣤⣿⢣⣿⣿⣿⣿⣿⣧⣴⣶⣶⣶⣖⣲⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢦⣜⡇⢘⣿⠀⠈⣿⣧⣿⣿⡇⢣⣿⣿⡎⣷⣘⣿⣏⢽⣎⠱" << endl;
    cout << "⣿⣿⠏⠀⣸⣿⡧⣾⠟⡅⣾⣿⣿⣿⣿⣻⣿⣿⡟⠻⡿⢿⣿⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠈⣷⡌⣿⢿⡀⢹⣿⣾⣿⡇⢣⢿⣿⣏⣿⣜⣿⣿⡞⡽⣖" << endl;
    cout << "⣿⠏⠀⣰⣿⠯⣽⢏⣼⠻⣿⢳⣿⣿⣿⠁⠙⠛⠷⣤⣙⠲⠧⠟⡛⠻⠅⠀⠀⠀⠀⠀⠀⠀⢀⡀⣴⡿⠿⠽⣿⣶⣦⢤⣼⣶⣟⡘⣧⡙⣯⢿⣿⡸⡱⣮⣿⣯⢽⡟⣾⣿⣟⡼⢹" << endl;
    cout << "⢋⠄⢰⣿⠏⢘⣿⣯⣼⠀⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠻⣿⣿⣿⣦⣤⣈⡉⣿⣯⡽⡟⠆⢿⠠⢿⣻⣧⣻⣧⠗⡼⣿⣿⡝⣖⢻⣿⣞⠷" << endl;
    cout << "⠋⢰⣿⠋⣠⣾⢟⣁⢾⣵⣿⣷⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠺⠻⢿⡿⢿⣿⣿⠧⣷⣼⡿⣘⣿⡗⣿⡜⡧⢎⣹⣿⡏⣾⢣⣿⣿⣮" << endl;
    cout << "⣶⠟⣣⣾⣿⣿⡖⣴⣾⣿⣿⣿⣿⣹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⠟⣿⠀⣿⡿⣿⣼⣿⢹⣿⣿⡗⡨⣜⣿⣟⡔⣣⢻⣷⣻" << endl;
    cout << "⣯⣾⣿⣿⣿⣻⣴⣿⣿⣿⣿⣿⢿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣤⣿⠟⠻⣷⣿⣇⣿⣿⡘⣾⣿⣿⣷⡱⣌⢳⡭⣿⡄⢻⡜⣿" << endl;
    cout << "⣿⣿⣿⣿⡏⣷⣿⣿⣿⣿⡿⣿⡟⣿⢿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⠀⢀⣾⣿⣿⣿⣇⢺⣿⣿⣟⣿⣿⡆⣏⢔⠻⡌⠷⡰⢛" << endl;
    cout << "⣿⣿⣿⣿⣗⢸⢻⣿⣿⣿⣿⣿⣿⡘⢷⡝⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⡇⣾⡞⣿⢭⣿⣷⢟⠧⣾⣷⣶⣹⣶⣍" << endl;
    cout << "⣿⣿⡿⣿⣿⣾⣽⣿⣿⣿⣿⣿⡻⢷⣙⣷⡜⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣟⣽⣿⣟⣧⣻⡇⡛⢦⣿⣿⢺⣟⢷⣻⣯⢳⣿⣿" << endl;
    cout << "⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣸⢿⣽⣷⡿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⡿⢹⣿⣿⣿⣏⣿⣃⢣⣾⣿⣏⣾⣟⣼⡻⣯⢾⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣞⢿⣿⣷⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣿⣿⠏⡔⣿⢿⣿⣿⣿⣺⣷⡿⣿⠟⣽⣳⣿⡲⣿⡴⣻⣿⣽" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⢷⠻⣿⣷⣧⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⠛⠠⢘⣼⠋⣼⣿⣿⣿⡷⣿⣿⣟⣾⣿⣟⣿⣷⢫⣷⣿⣻⢿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣯⠹⣿⡷⣻⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⡿⠋⠀⡌⣴⡿⢡⠂⣿⣿⣿⣿⣿⣽⣿⣿⣿⣟⡾⣿⣽⣾⣯⢿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡧⣹⣷⣹⢿⣿⣿⣷⣄⡀⠀⠀⢀⣀⣤⣶⣿⣿⣿⣿⣿⠟⠀⢀⡶⢿⡿⢁⢦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣥⡹⣿⣾⡹⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⠿⢡⠠⠒⠀⣼⡟⣱⢯⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠜⡹⣷⡝⣎⣿⣿⣽⣿⣗⣫⣿⣿⣿⡿⠛⠁⠀⠀⠀⢠⣾⠏⠜⣱⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⠄⠑⢞⠻⢬⢍⠻⢿⣿⣿⣟⡿⠟⠁⠠⠀⠊⠁⢀⣰⠟⢁⠠⠚⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠈⢣⠄⠂⠡⠀⠹⣿⣿⣄⠀⠀⠀⠀⠀⣠⡞⠁⠈⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡄⠀⠑⠘⠀⠀⠀⠉⠘⢿⡿⢦⣀⣠⣞⠋⠀⠀⠀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⡀⠠⠀⠀⠀⠀⠀⠀⠹⣷⡽⠟⢁⣀⣀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣷⣮⣄⠀⠀⠀⠘⢿⡖⢣⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢦⡀⠀⣀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢛⣿⣿⣿⣿⣿⣻⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡎⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢂⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣜⠻⠿⢿⣿⣿⣿⣿⣿⣿⣟⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣶⣶⣯⣽⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
cout << "Press any key to continue." << endl;
}

    /*cout << "You find yourself stuck in a maze. Looking around, there are 0 maidens in the maze. Maybe if you choose the Tarnished route you would find a maiden." << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢮⠿⠧⠒⠚⠉⠋⢉⣀⣤⣾⣧⣢⢄⣀⠀⠀⢺⣶⡄⠉⠀⠀⢀⣀⠠⢁⡓⣬⢑⡾⢯⠹⡜⣿⣿⡝⣿⢋⡻⣿⣻⣟⣻⢿⣻⣟⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⡟⠛⣿⠛⢻⣿⡿⠛⠉⠛⢦⣄⢠⢤⣿⠓⠒⢻⡟⠛⠛⣿⣿⠛⠛⠛⣷⣾⡟⠛⣶⣿⠛⠛⠛⠻⣦⣷⠛⠛⠛⢷⣿⠛⢻⡟⠛⢿⣶⠟⠛⠙⠻⣾⣿⠞⠋⠛⠻⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⡇⠀⠹⠀⢸⣿⡇⠀⣿⠀⠀⡧⠡⣸⣿⠀⠀⢸⡇⠀⠀⣿⣿⠀⢀⠀⢻⣿⡇⠀⣿⣿⠀⢸⡇⠀⢸⣿⠀⠀⣷⣿⣿⠀⠀⢷⠀⣿⣿⠀⠹⣦⣤⣿⣿⣄⣸⠂⠀⣹⣿" << endl;
    cout << "⣿⣿⣿⣿⠀⠀⠀⠀⢸⣿⡇⠀⣿⠀⠀⣧⣷⣿⣿⠀⢸⠀⠀⡆⠀⣿⡏⠀⢸⠀⠸⣿⡇⠀⢾⣿⠀⢸⡇⠀⢸⢾⠀⢀⣈⣿⣿⠀⢀⠀⠀⣿⣿⣦⣀⠀⠙⣿⣿⠉⠙⠁⠀⣼⣿" << endl;
    cout << "⣿⣿⣿⣿⠀⠀⡆⠀⢸⣿⡇⠀⠿⡄⢀⣿⣿⢻⣷⠀⢸⡀⢀⡇⢀⣿⡇⠀⣠⡀⠀⣿⣇⠀⣻⣿⠀⠸⠇⠀⣸⣿⠀⠀⠿⢿⣿⠀⢸⡀⠀⢿⣿⠀⠸⠇⠀⣸⣿⠶⢾⣶⣾⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣶⣴⣿⣦⡼⠟⠛⢶⣤⣾⣿⣿⠏⣼⢿⢴⣾⣷⣾⣷⠶⠛⠳⠦⠟⠳⠶⠟⠳⠶⠟⠹⢶⣶⢾⣿⣿⡿⣷⣷⣦⡾⠻⠶⠼⠷⠶⠾⢿⣷⣤⡤⠾⠻⠻⠦⢾⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⠋⠀⢠⡖⣩⣾⣿⠟⡁⡾⠃⠀⣮⣿⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡸⣿⣿⣷⠀⢹⣮⣧⠀⠀⢣⡀⠀⢠⠈⢿⡧⣼⠁⡄⢣⠐⠀⢻⣿⣿⣾" << endl;
    cout << "⣿⣽⣿⣻⣿⡿⠁⠀⣴⢋⣼⣿⠿⠋⣰⠇⠀⢀⣶⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢷⢻⣻⢿⡄⠂⣽⣿⡄⡘⠌⢓⠀⠂⠐⠘⢿⣼⣷⢀⠈⡲⢦⣆⡿⣿⣿" << endl;
    cout << "⣿⢷⣯⣿⠟⠀⢀⡞⢡⣾⠟⠁⢠⣾⠏⠀⠀⣼⢿⣿⠇⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣾⡄⣿⡆⠐⡈⣿⡏⣑⠣⢌⠃⠀⠉⣤⣦⡉⢿⣿⣇⠺⣥⣞⡵⡹⣿" << endl;
    cout << "⡿⣯⣿⠋⢀⡴⣋⣴⠟⠁⠀⣰⣿⠏⢀⠀⣸⣯⣿⡟⠀⠀⠀⠀⡠⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣇⠸⣷⡐⡀⢹⣷⣌⢝⠢⢌⢠⡁⣹⣿⣧⠈⢿⣿⡳⡆⡝⣜⢡⢻" << endl;
    cout << "⢷⣿⢏⠀⡞⡼⠉⠁⡴⢫⣾⣿⡣⢰⠇⣀⣿⣿⣿⠃⠀⠀⠀⠀⠀⣠⣼⡇⠀⠀⠀⠀⠀⠀⠀⢀⣴⡖⠀⠳⢻⡀⢻⣷⠀⠀⠛⢾⣏⡝⢦⠀⡷⢸⣿⣿⠷⣮⣽⣷⣋⠖⡭⢦⣉" << endl;
    cout << "⣾⠏⣿⠀⠀⠀⢀⣾⣷⢟⢞⡽⣡⡿⣴⣿⣿⡟⠉⢀⣀⣠⣴⡾⠿⠿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⢻⣷⡄⠀⠈⢷⡘⣿⣯⠐⡈⠘⣿⡜⣯⡒⣿⡆⢻⣿⢯⢹⡿⣿⡗⣞⢰⠛⣶" << endl;
    cout << "⣿⢰⡇⠀⢀⢠⣿⡿⠋⢠⣾⢷⣿⣵⣿⣿⣿⠿⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠿⣶⣄⠀⠹⣇⠛⣷⡁⢀⢹⣿⡹⣷⣿⣏⠈⣿⣟⠦⣓⢿⣿⡌⢧⡋⠴" << endl;
    cout << "⣿⣿⡇⠐⢀⣾⡿⢃⣤⣿⢣⣿⣿⣿⣿⣿⣧⣴⣶⣶⣶⣖⣲⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢦⣜⡇⢘⣿⠀⠈⣿⣧⣿⣿⡇⢣⣿⣿⡎⣷⣘⣿⣏⢽⣎⠱" << endl;
    cout << "⣿⣿⠏⠀⣸⣿⡧⣾⠟⡅⣾⣿⣿⣿⣿⣻⣿⣿⡟⠻⡿⢿⣿⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠈⣷⡌⣿⢿⡀⢹⣿⣾⣿⡇⢣⢿⣿⣏⣿⣜⣿⣿⡞⡽⣖" << endl;
    cout << "⣿⠏⠀⣰⣿⠯⣽⢏⣼⠻⣿⢳⣿⣿⣿⠁⠙⠛⠷⣤⣙⠲⠧⠟⡛⠻⠅⠀⠀⠀⠀⠀⠀⠀⢀⡀⣴⡿⠿⠽⣿⣶⣦⢤⣼⣶⣟⡘⣧⡙⣯⢿⣿⡸⡱⣮⣿⣯⢽⡟⣾⣿⣟⡼⢹" << endl;
    cout << "⢋⠄⢰⣿⠏⢘⣿⣯⣼⠀⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠻⣿⣿⣿⣦⣤⣈⡉⣿⣯⡽⡟⠆⢿⠠⢿⣻⣧⣻⣧⠗⡼⣿⣿⡝⣖⢻⣿⣞⠷" << endl;
    cout << "⠋⢰⣿⠋⣠⣾⢟⣁⢾⣵⣿⣷⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⠺⠻⢿⡿⢿⣿⣿⠧⣷⣼⡿⣘⣿⡗⣿⡜⡧⢎⣹⣿⡏⣾⢣⣿⣿⣮" << endl;
    cout << "⣶⠟⣣⣾⣿⣿⡖⣴⣾⣿⣿⣿⣿⣹⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⠟⣿⠀⣿⡿⣿⣼⣿⢹⣿⣿⡗⡨⣜⣿⣟⡔⣣⢻⣷⣻" << endl;
    cout << "⣯⣾⣿⣿⣿⣻⣴⣿⣿⣿⣿⣿⢿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣤⣿⠟⠻⣷⣿⣇⣿⣿⡘⣾⣿⣿⣷⡱⣌⢳⡭⣿⡄⢻⡜⣿" << endl;
    cout << "⣿⣿⣿⣿⡏⣷⣿⣿⣿⣿⡿⣿⡟⣿⢿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠟⠁⠀⢀⣾⣿⣿⣿⣇⢺⣿⣿⣟⣿⣿⡆⣏⢔⠻⡌⠷⡰⢛" << endl;
    cout << "⣿⣿⣿⣿⣗⢸⢻⣿⣿⣿⣿⣿⣿⡘⢷⡝⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⡇⣾⡞⣿⢭⣿⣷⢟⠧⣾⣷⣶⣹⣶⣍" << endl;
    cout << "⣿⣿⡿⣿⣿⣾⣽⣿⣿⣿⣿⣿⡻⢷⣙⣷⡜⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣟⣽⣿⣟⣧⣻⡇⡛⢦⣿⣿⢺⣟⢷⣻⣯⢳⣿⣿" << endl;
    cout << "⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣸⢿⣽⣷⡿⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⡿⢹⣿⣿⣿⣏⣿⣃⢣⣾⣿⣏⣾⣟⣼⡻⣯⢾⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣞⢿⣿⣷⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣿⣿⠏⡔⣿⢿⣿⣿⣿⣺⣷⡿⣿⠟⣽⣳⣿⡲⣿⡴⣻⣿⣽" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⢷⠻⣿⣷⣧⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⣿⠛⠠⢘⣼⠋⣼⣿⣿⣿⡷⣿⣿⣟⣾⣿⣟⣿⣷⢫⣷⣿⣻⢿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣯⠹⣿⡷⣻⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⣿⣿⡿⠋⠀⡌⣴⡿⢡⠂⣿⣿⣿⣿⣿⣽⣿⣿⣿⣟⡾⣿⣽⣾⣯⢿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡧⣹⣷⣹⢿⣿⣿⣷⣄⡀⠀⠀⢀⣀⣤⣶⣿⣿⣿⣿⣿⠟⠀⢀⡶⢿⡿⢁⢦⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣥⡹⣿⣾⡹⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⠿⢡⠠⠒⠀⣼⡟⣱⢯⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠜⡹⣷⡝⣎⣿⣿⣽⣿⣗⣫⣿⣿⣿⡿⠛⠁⠀⠀⠀⢠⣾⠏⠜⣱⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⠄⠑⢞⠻⢬⢍⠻⢿⣿⣿⣟⡿⠟⠁⠠⠀⠊⠁⢀⣰⠟⢁⠠⠚⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠈⢣⠄⠂⠡⠀⠹⣿⣿⣄⠀⠀⠀⠀⠀⣠⡞⠁⠈⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡄⠀⠑⠘⠀⠀⠀⠉⠘⢿⡿⢦⣀⣠⣞⠋⠀⠀⠀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⡀⠠⠀⠀⠀⠀⠀⠀⠹⣷⡽⠟⢁⣀⣀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣷⣮⣄⠀⠀⠀⠘⢿⡖⢣⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢦⡀⠀⣀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢛⣿⣿⣿⣿⣿⣻⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡎⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡧⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢂⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣜⠻⠿⢿⣿⣿⣿⣿⣿⣿⣟⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;
    cout << "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣶⣶⣯⣽⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿" << endl;*/