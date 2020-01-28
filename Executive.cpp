#include "Executive.h"
#include <unistd.h>

Executive::Executive(std::string fileName)
{
  this->fileName = fileName;
  ptr = new LinkedList<int>;
}

Executive::~Executive()
{
  delete ptr;
}

void Executive::run()
{
  int num;

  std::ifstream inFile;
  inFile.open(fileName);

  fileRetry(inFile);
  while(num != 11)
  {
    clear();
    printMenu();

    std::cin >> num;
    executeOrders(num);
    usleep(1500000);
  }
}

void Executive::fileRetry(std::ifstream &i)
{
  while(!i.is_open())
  {
    std::cout << "\nIncorrect file name. Please try again.\n\n";
    std::cout << "\n\n\n\n\n\n";
    std::cout << "Input the name of your file: ";
    std::cin >> fileName;
    i.open(fileName);
  }
}

void Executive::printMenu()
{
  std::cout << "Choose one of the options below: \n\n";
  std::cout << "\t1. Is Empty\n"
            << "\t2. Length\n"
            << "\t3. Insert\n"
            << "\t4. Delete\n"
            << "\t5. Delete Duplicates\n"
            << "\t6. Find\n"
            << "\t7. Find Next\n"
            << "\t8. Print\n"
            << "\t9. Reverse List\n"
            << "\t10. Print At\n"
            << "\t11. Exit\n";
  std::cout << "Your choice: ";
}

void Executive::clear()
{
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int Executive::getUserInput()
{
  int num;
  std::cin >> num;
  return num;
}

void Executive::executeOrders(int num)
{
  switch(num) {
    int userPick;

    case 1:
      if(ptr->isEmpty())
        std::cout << "This list is empty.\n";
      else
        std::cout << "This list is NOT empty.\n";
      break;

    case 2:
      std::cout << "The length of this list is " << ptr->getLength() << '\n';
      break;

    case 3:
      std::cout << "What number do you want to insert? ";
      std::cin >> userPick;
      ptr->insert(1, userPick);
      break;

    case 4:

      break;

    case 5:
      break;

    case 6:
    {
      bool flag = false;
      int position = 0;
      std::cout << "Which number do you want to search for?: ";
      std::cin >> userPick;
      if(ptr->isEmpty())
      {
        std::cout << "List is empty.\n";
      }
      else
      {
        for(int i = 1; i <= ptr->getLength(); i++)
        {
          if(userPick == ptr->getEntry(i))
          {
            flag = true;
            position = i;
            break;
          }
        }
        if(flag)
        {
          std::cout << "FOUND " << userPick << " at position " << position << ".\n";
        }
        else
        {
          std::cout << "\n\n" << userPick << " NOT FOUND.\n";
        }
      }
      break;
    }

    case 7:
    {
      int position= 0;
      std::cout << "At which position do you want to see the next element?: ";
      std::cin >> position;
      if(ptr->isEmpty())
      {
        std::cout << "\n\n List is empty.\n";
      }
      else
      {
        try
        {
          std::cout << "Here is the next element after position " << position << ": " << ptr->getEntry(position+1);
        }
        catch(std::runtime_error rte)
        {
          std::cout << rte.what() << '\n';
        }
      }

      break;
    }

    case 8:
      std::cout << "Your linked list: ";
      for(int i = 1; i <= ptr->getLength(); i++)
      {
        std::cout << ptr->getEntry(i) << ' ';
      }
      std::cout << '\n';
      break;

    case 9:
      try
      {
        ptr->reverse();
        std::cout << "Your reversed linked list: ";
        for(int i = 1; i <= ptr->getLength(); i++)
        {
          std::cout << ptr->getEntry(i) << ' ';
        }
        std::cout << '\n';
      }
      catch(std::runtime_error rte)
      {
        std::cout << rte.what() << '\n';
      }
        break;

    case 10:
      std::cout << "Which index do you want to see?: ";
      std::cin >> userPick;

      try
      {
        std::cout << "The element at index " << userPick << " is: " << ptr->getEntry(userPick) << '\n';
      }
      catch(std::runtime_error rte)
      {
        std::cout << rte.what() << '\n';
      }
      break;

    case 11:
      std::cout << "\n\nGoodbye.\n\n";
      usleep(1000000);
      break;

    default:
      std::cout << "\n\nInvalid choice.\n\n";

  }
}