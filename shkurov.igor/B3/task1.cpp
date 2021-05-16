#include <iostream>
#include <string>
#include <sstream>

#include "PhoneBook.hpp"
#include "BookWrap.hpp"
#include "tools.hpp"
#include "tasks.hpp"

namespace lab = shkurov;

int lab::task1(std::istream& in, std::ostream& out)
{
  int returnVal = 0;

  lab::PhoneBook book;
  lab::BookWrap wrapper(book, out);

  std::string command;

  while (std::getline(in, command) && !command.empty())
  {
    std::istringstream istr(command);

    std::string tag;
    istr >> tag;

    try
    {
      wrapper.doAction(tag, istr);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what();
      returnVal = 2;
    }
  }
  if (in.fail() && !in.eof())
  {
    return returnVal;
  }
  return 0;
}
