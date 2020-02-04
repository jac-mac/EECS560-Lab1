#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <limits>


using namespace std;

class Executive
{
  private:
  std::string fileName;
  LinkedList<int>* ptr;

  public:
  /*
   *@pre None.
   *@post Passes a string into the constructor, sets it to private fileName
   *@param fileName is the name of a file needing to be read.
   *@return None.
   */
  Executive(std::string fileName);

  /*
   *@pre None.
   *@post Reallocates memory used by new. Namely ptr.
   *@param None.
   *@return None.
   */
  ~Executive();

  /*
   *@pre Executive object has to be created.
   *@post Main flow of control for the program
   *@param None.
   *@return None.
   */
  void run();

  /*
   *@pre fileName has to exist in the directory this program is in.
   *@post If the fileName is wrong, goes through a while loop to keep trying to open the file.
   *@param i is the instance of the ifstream class used to open and read files.
   *@return None.
   */
  void fileRetry(std::ifstream &i);

  /*
   *@pre Executive object has to be created.
   *@post Prints out a menu.
   *@param None.
   *@return None.
   */
  void printMenu();

  /*
   *@pre Executive object has to be created.
   *@post Resets the terminal window. Makes the terminal look less cluttered.
   *param None.
   *return None.
   */
  void clear();

  /*
   *@pre A menu has to be shown allowing the user to choose which option they want using numbers.
   *@post hands back the int of the choice the user makes.
   *@param None.
   *@return Returns the user's choice.
   */
  int getUserInput();

  /*
   *@pre Requires a userInput. Will be given it by getUserInput
   *@post In charge of the switch cases of the menu provided
   *param num is the user's choice
   *return None.
   */
  void executeOrders(int num);

  /*
   *@pre fileName must be correct, must exist in same directory as this program.
   *@post Reads in from the file the numbers waiting to be inserted into the LinkedList.
   *param i is the instance of the ifstream class used to open and read files.
   *return None.
   */
  void initializeList(std::ifstream &i);
};
#endif
