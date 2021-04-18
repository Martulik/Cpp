#include <iostream>
#include <sstream>

#include "tasks.hpp"

namespace fer = ferapontov;

template< typename T >
T readArg(std::string arg)
{
  T res;
  std::stringstream in(arg);
  if(!(in >> res))
  {
    std::cerr << "Invalid Argument";
    std::exit(-1);
  }
  return res;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Invalid Arguments";
    std::exit(-1);
  }

  int TaskNumber = readArg< int >(argv[1]);
  std::string mode = readArg< std::string >(argv[2]);

  if(TaskNumber > 4 || TaskNumber < 1)
  {
    std::cerr << "Invalid number of the Task";
    std::exit(-1);
  }
  else if(TaskNumber == 1)
  {
    fer::task1(mode);
  }
  return 0;
}
