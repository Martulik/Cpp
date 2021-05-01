#include "phonebook.hpp"
#include <stdexcept>

namespace poz = pozdnyakov;

poz::Phonebook::Phonebook():
  currEntry(entries.begin())
{
}

void poz::Phonebook::showCurrent(std::ostream& out)
{
  out << *currEntry[0] << ' ' << *currEntry[1] << '\n';
}

void poz::Phonebook::nextEntry()
{
  if (currEntry == std::prev(entries.end()))
  {
    throw std::runtime_error("Out of range");
  }
  currEntry++;
}

void poz::Phonebook::prevEntry()
{
  if (currEntry == entries.begin())
  {
    throw std::runtime_error("Out of range");
  }
  currEntry--;
}

void poz::Phonebook::insertEntry(std::pair< std::string, std::string > entry)
{

}

void poz::Phonebook::pushBackEntry(std::pair< std::string, std::string > entry)
{
}

void poz::Phonebook::move(int n)
{
}
