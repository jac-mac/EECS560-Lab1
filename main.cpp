#include "Executive.h"
#include <iostream>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "\nIncorrect number of parameters! Please include the name of the data file on the command line.\n\n";
  }
  else
  {
     Executive exec(argv[1]); //sample creation of executive object
     exec.run(); //presumably handles the calling of all other member methods
  }

  return(0);
}
