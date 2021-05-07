#include "task1.hpp"
#include "bookmarks.hpp"
#include "commands.hpp"
#include <iostream>

namespace iva = ivanova;

int iva::task1()
{
  iva::Bookmarks bookmark;
  std::string str;
  while (std::getline(std::cin, str))
  {
    if (std::cin.fail())
    {
      std::cerr << "Read fail";
    }
    std::string command;
    std::stringstream input(str);
    input >> command;
    Commands fnc;
    fnc.doCommand(command, bookmark, input);
  }
  if (!std::cin.eof())
  {
    std::cerr << "Failed reading";
    return 1;
  }
  return 0;
}
