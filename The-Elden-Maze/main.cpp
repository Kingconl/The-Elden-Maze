#include <iostream>
//#include "Maze.h"
#include "Player/Player.h"
#include "Player/Algorithm.h"
#include "Getch.h"
#include <limits> 

int menu(string, string[], int);

int main()

{
  int userInput = 0;
  string promt = "The Elden Maze";
  string promtOptions[4] = { "Maidnlesses", "Ranni", "Tarnished", "Exit Program"};
  int numberOfPromtOptions = 4;

  Player MC;
  Algorithm Al;
  Adventure Helen;

  do {
    userInput = menu(promt, promtOptions, numberOfPromtOptions);

    switch (userInput)
    {
    case 1:

      MC.tick();

      break;

    case 2:
      Al.tick();

      break;

    case 3:
      Helen.tick();

      break;
    
    case 4:
      cout << "Closing The Elden Maze";
      break;
    }
  } while (userInput != numberOfPromtOptions);

  return 0;
}


int menu(string question, string option[], int numberOfOptions)
{
  Getch g;
  int userReponse = 0;
  do {
    (void)system("clear");

    cout << question << endl;

    for (int i = 0; i < numberOfOptions; i++)
    {
      cout << i + 1 << "- " << option[i] << endl;//couts the options
    }

    cin >> userReponse;
    if (cin.fail())//sets any value that cant be stored as an int as 0. 
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (userReponse < 1 or userReponse > numberOfOptions)
    {
      cout << "Invalid answer. Try again" << endl << "Press any key to continue.";
      g.pause();
      (void)system("clear");
    }
    (void)system("clear");

  } while (userReponse < 1 or userReponse > numberOfOptions);//if it does not fall within the parameters, loop again.
  return userReponse;
}