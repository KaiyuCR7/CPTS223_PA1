/******************************************************************************************
    NAME: KAIYU ADACHI, CLASS: CPTS 223
    PROJECT: PA1 -- LEARNING LINUX COMMANDS MATCHING GAME AND C++ REVIEW
*******************************************************************************************/
/*
  ADVANTAGE/DISADVANTAGE LINKED LIST:
  ADVANTAGE: 
  - The dynamic size, meaning it can grow or shrink during runtime.
  - Insertions and deletions can be done in constant time
  - Since linked list allocate memory, it will not waste memory.

  DISADVANTAGE: 
  - Acessing elements means traversing through, which makes time compleixty longer.
  - This also means cannot access things randomly such as array[i].
  - Increase of memory due to pointers.
*/

/*
  ADVANTAGE/DISADVANTAGE ARRAY:
  ADVANTAGE: 
  - Constant time
  - Memory efficient since no memory overhead.
  - Can access any position within array easily

  DISADVANTAGE: not as easy to resize as compared to linked list.
  - At compile time the size is fixed
  - If you want to insert or delete you have to shift elements
  - Arrays can allocate more memory than needed
*/

#include "endFunctions.hpp"
#include "inFunctions.hpp"
#include "root.hpp"

int main() {
  // TEST CODE:
  std::string a = "Hello!";
  std::cout << std::endl << "THIS IS A TEST: " + a << std::endl << std::endl;

  //test

  // CREATE A SEED FOR RANDOMIZATION:
  srand((unsigned int)time(NULL));

  // CREATE A BUFFER TO HOLD ALL COMMANDS:
  std::vector<Data> cmdBuffer;
  populateBufferVector(cmdBuffer);

  // POPULATE A NEW LIST WITH COMMANDS FROM BUFFER:
  List<Node<Data>> activeCmdList;
  populateList(activeCmdList, cmdBuffer);

  // CREATE A PLAYER PROFILE:
  Player activePlayer;
  activePlayer.setPlayerInfo();

  // **************************************************************************************
  // DISPLAY MENU AND LET USER CHOOSE AN OPTION:
  // **************************************************************************************
  int menuChoice = 0;
  while (menuChoice != 6) {
    printMenu();
    menuChoice = getMenuOption();

    switch (menuChoice) {
      case 1:
        std::cout << std::endl << "\tOPTION 1: GAME RULES. . ." << std::endl;
        printGameRules();
        break;
      case 2:
        activePlayer.hardRESETpoints();
        std::cout << std::endl << "\tOPTION 2: STARTING GAME. . ." << std::endl;
        playGame(cmdBuffer, activeCmdList, activePlayer);
        break;
      case 3:
        std::cout << std::endl
                  << "\tOPTION 3: LOADING PREVIOUS GAME. . ." << std::endl;
        loadPreviousGame(cmdBuffer, activeCmdList, activePlayer);
        break;
      case 4:
        std::cout << std::endl << "\tOPTION 4: ADD COMMAND. . ." << std::endl;
        addCommand(activeCmdList, cmdBuffer);
        break;
      case 5:
        std::cout << std::endl
                  << "\tOPTION 5: REMOVE COMMAND. . ." << std::endl;
        removeCommand(activeCmdList /*, cmdBuffer*/);
        break;
      case 6:
        std::cout << std::endl << "\tEXITING. . ." << std::endl << std::endl;

        break;
    }
  }

  writeToCmdFile(activeCmdList);
  writeToProfiles(activePlayer);
  activeCmdList.~List();
  return 0;
}