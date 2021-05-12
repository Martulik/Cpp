#include "task1.hpp"
#include "bookmarks.hpp"
#include "commands.hpp"
#include <iostream>

namespace iva = ivanova;

int iva::task1(std::istream &in, std::ostream &out)
{
  iva::Bookmarks bookmark;
  std::string str;
  while (std::getline(in, str))
  {
    if (std::cin.fail())
    {
      std::cerr << "Read fail";
      return 1;
    }
    std::string command;
    std::stringstream input(str);
    input >> command;
    Commands fnc(std::cout);
    fnc.doCommand(command, bookmark, input);
  }
  if (!std::cin.eof())
  {
    std::cerr << "Failed reading";
    return 1;
  }
  return 0;
}
