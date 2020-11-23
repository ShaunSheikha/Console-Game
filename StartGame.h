#include "PlayerClass.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>



void pressEnter(){
  std::cout << std::endl << "Press enter..." << std::endl << std::flush;
  std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int checkChoiceInput(){
  int path;
  int badInput;
  do{
    badInput=0;
    std::cin >> path;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    if(!std::cin)
    {
      badInput=1;
      std::cin.clear();
      std::cout << "Enter a valid path, or else! " << std::endl;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }while(badInput);

  return path;

}

void gameBanner(){
  std::cout << std::setfill('_') << std::setw(100) << "" << std::endl;
  std::cout << std::setfill('*') << std::setw(100) << ""<<std::endl;
  std::cout << std::setw(100) << "" << std::endl;
  std::cout << std::setw(25) << "" << std::setw(40) << " WELCOME | TO | YOUR | DOOM " << std::setw(35) << "" << std::endl;
  std::cout << std::setw(100) << "" << std::endl;

  std::cout << std::setw(100) << "" << std::endl;
  std::cout << std::setfill('_') << std::setw(100) << "" << std::endl;
  std::cout << std::setfill(' ') << std::setw(40) << ""<< "Press Enter to die: " << std::setw(40) << "" << std::endl;
  std::cout << std::setfill('_') << std::setw(100) << "" << std::endl;


  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

}

void startBear(){
  printf(R"EOF(
      _     _
     (c).-.(c)
      / ._. \        HELLO FRIEND,
    __\( Y )/__
   (_.-/'-'\-._)          I will kill you.          to DEATH
      || X ||
    _.' `-' '._
   (.-./`-'\.-.)                            : )
    `-'     `-'
 )EOF");
 std::cout << std::setfill('_') << std::setw(100) << "" << std::endl;

 pressEnter();

}

void endBear(){
  printf(R"EOF(
                          _     _
                         (c).-.(c)
                          / ._. \
                        __\( Y )/__
        YOU'RE         (_.-/'-'\-._)         DEAD
                          || 0 ||
                        _.' `-' '._
                       (.-./`-'\.-.)
                        `-'     `-'
 )EOF");
 std::cout << std::setfill('_') << std::setw(100) << "" << std::endl;

 pressEnter();



}

void enemyEncounter(Player& player){
  Enemy en;
  en.printStats();
  en.makeNoise();
  pressEnter();
  int choice;

  for (size_t i = 1;player.isAlive() && en.isAlive() ; i++) {
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

    std::cout << "Round ";
    std::cout << i << std::endl << std::endl;
    player.printStats();
    en.printStats();
    std::cout << "Actions: " << std::endl;
    std::cout << std::setw(20) << "[1]Attack " << std::setw(20) << "[2]Combo " << std::endl;
    choice = checkChoiceInput();

    switch (choice) {
      case 1:
        player.whack(en);
        break;
      case 2:
        player.combo(en);
        break;
      default:
        std::cout << "defaulted move. You stand there like an idiot!" << std::endl;
    }

    if(en.isAlive()){
      std::cout << en.retName() << ": YOU LOOK TERRIBLE" << std::endl;
      en.attack(player);
    } else {
      std::cout << en.retName() << " has been defeated. " << std::endl;
    }

    pressEnter();
  }

  std::cout << "Final Battle Results: " << std::endl;
  player.printStats();
  en.printStats();
  pressEnter();
}

void paradise(Player& player){
  std::cout << std::endl;
  std::cout << "what the hell is that smell?..." << std::endl;
  pressEnter();
  std::cout << "You encounter a creature. " << std::endl;
  pressEnter();

  enemyEncounter(player);


  std::cout << "You realize this place kind of sucks and leave." << std::endl;
  pressEnter();

}

void radioshack(Player& player){
  std::cout << std::endl;
  std::cout << "You're going to need to sit down for this one buddy..." << std::endl;
  pressEnter();
  std::cout << "Only about 400 stores remain after they declared bankruptcy in 2015." << std::endl;
  pressEnter();
  std::cout << "..." << '\n';
  pressEnter();
  std::cout << "Listen, please stop crying. " << '\n';
  pressEnter();
  std::cout << "You lose health at this grave news." << std::endl;
  player.attack(player,2);
  player.printStats();
  pressEnter();
  std::cout << "An enemy appears to laugh at your grief " << std::endl;
  pressEnter();
  enemyEncounter(player);


}

void oblivion(Player& player){
  std::cout << std::endl;
  std::cout << "hey this place isn't all that bad. :)" << std::endl;
  pressEnter();

  std::cout << "Would you like to stay a while? " << std::endl << std::endl;
  std::cout << std::setw(40) << "[1] Yes" << std::setw(40) << "[2] No" << std::endl;

  int choice;
  choice = checkChoiceInput();

  switch (choice) {
    case 1:
      std::cout << "You enjoy the silence for an eternal moment " << std::endl;
      pressEnter();
      break;
    case 2:
      std::cout << "You exit the oblivion." << std::endl;
      pressEnter();
      break;
    default:
      std::cout << "oblivion go brrrrr " << std::endl;
      pressEnter();
      player.attack(player,10);
      player.printStats();
      pressEnter();

  }



}

void startGame(){

  //Banner and bear-------------------------------------------------------------
  gameBanner();
  startBear();
  //----------------------------------------------------------------------------

  //Character creation----------------------------------------------------------
  std::cout << "Name your character: ";
  std::string input;
  getline(std::cin,input);

  std::cout << std::endl<< "Creating: " << input << std::endl << std:: endl;

  Player mainPlayer(input);

  std::cout << "Character Created " <<  std::endl << std::endl ;

  mainPlayer.yellName();
  mainPlayer.printStats();
  pressEnter();
  //----------------------------------------------------------------------------

  //Possible paths--------------------------------------------------------------
  std::cout << "Alright ya little dingus. Which way do you want to go? " << std::endl << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::setw(30) << "[1] Literal Paradise";
  std::cout << std::setw(30) << "[2] RadioShack";
  std::cout << std::setw(30) << "[3] Oblivion" << std::endl;

  int path = checkChoiceInput();
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

  //Off on the adventure--------------------------------------------------------
  switch (path) {
    case 1:
      paradise(mainPlayer);
      break;
    case 2:
      radioshack(mainPlayer);
      // mainPlayer.attack(mainPlayer,1000);
      break;
    case 3:
      oblivion(mainPlayer);
      break;
    default:
      std::cout << "The void consumes you and you attack yourself. " << std::endl;
      mainPlayer.attack(mainPlayer,1000);
      std::cout << std::endl;
  }
  //Back From the adventure-----------------------------------------------------

  std::cout << "Your sorry soul finds its way back to where you started " << std::endl << std::endl;
  pressEnter();

  std::cout << "Let's check those stats! " << std::endl;
  pressEnter();
  mainPlayer.printStats();


  //we always die in the end!---------------------------------------------------
  if (mainPlayer.isAlive()) {
    std::cout << "Oh good, you're still alive. Off to the bear with you. " << std::endl << std::endl;
    endBear();
    std::cout << "You enter a state of abject fear and decide to attack yourself." << std::endl;
    mainPlayer.attack(mainPlayer,100);
    mainPlayer.printStats();
    pressEnter();
  } else{
    std::cout << "Oh nevermind... you so dead...oh well, food for the bear." << std::endl;
    endBear();
  }
  //----------------------------------------------------------------------------

}
