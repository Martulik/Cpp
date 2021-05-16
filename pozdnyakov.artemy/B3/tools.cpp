#include "tools.hpp"
#include <algorithm>

namespace poz = pozdnyakov;

poz::Phonebook::iterator poz::getEntry(std::unique_ptr< poz::Phonebook >& book, std::string number)
{
  if (book->size() == 0)
  {
    return book->end();
  }
  auto cond = [&number](std::pair< std::string, std::string > entry)
  {
    return std::get< 0 >(entry) == number;
  };
  poz::Phonebook::iterator it = std::find_if(book->begin(), book->end(), cond);
  return it;
}

bool poz::checkNumber(std::unique_ptr< Phonebook >& book, std::string number)
{
  auto cond = [&number](std::pair< std::string, std::string > entry)
  {
    return number == std::get< 0 >(entry);
  };
  return (std::find_if(book->begin(), book->end(), cond) != book->end());
}
