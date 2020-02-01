#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "LinkedList.h"
#include <fstream>
#include <iostream>

class Executive
{
  private:
  std::string fileName;
  LinkedList<int>* ptr;

  public:
  Executive(std::string fileName);
  ~Executive();
  void run();
  void fileRetry(std::ifstream &i);
  void printMenu();
  void clear();
  int getUserInput();
  void executeOrders(int num);
  void initializeList(std::ifstream &i);
};
#endif
