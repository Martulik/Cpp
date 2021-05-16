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
  lab::PhoneBook book;
  lab::BookWrap wrapper(book, out);

  std::string command;

  while (std::getline(in, command) && !in.eof())
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
      std::cerr << ex.what() << '\n';
    }
  }

  return 2;
}
