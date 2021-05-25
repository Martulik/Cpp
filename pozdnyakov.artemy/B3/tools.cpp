#include "tools.hpp"
#include <algorithm>

namespace poz = pozdnyakov;

poz::Phonebook::const_iterator poz::getEntryByNumber(std::unique_ptr< poz::Phonebook >& book, std::string number)
{
  if (book->size() == 0)
  {
    return book->cend();
  }
  auto cond = [&number](std::pair< std::string, std::string > entry)
  {
    return std::get< 0 >(entry) == number;
  };
  poz::Phonebook::const_iterator it = std::find_if(book->cbegin(), book->cend(), cond);
  return it;
}

bool poz::checkNumber(std::unique_ptr< Phonebook >& book, std::string number)
{
  auto cond = [&number](std::pair< std::string, std::string > entry)
  {
    return number == std::get< 0 >(entry);
  };
  return (std::find_if(book->cbegin(), book->cend(), cond) != book->cend());
}
