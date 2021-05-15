#include "task1.hpp"

#include <iostream>

#include "bookmarks.hpp"
#include "commands.hpp"


namespace iva = ivanova;

int iva::task1(std::istream &in, std::ostream &out)
{
  Commands book(out);
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
    book.doCommand(command, input);
  }
  if (!std::cin.eof())
  {
    std::cerr << "Failed reading";
    return 1;
  }
  return 0;
}
