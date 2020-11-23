//Imports
#include <iostream>
#include <limits>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

//Custom imports!
#include "StartGame.h"



int main(){

  bool playing = false;
  char response = 'n';

  do {
    startGame();
    std::cout << std::endl << "Do you want to play again? [y = yes]" << '\n';
    std::cin >> response;
    response == 'Y' || response == 'y' ? playing = true : playing = false;

  } while(playing);

  //-------------------------------------------------

  //-------------------------------------------------

  return 0;
}
