#include "phonebook.hpp"
#include <stdexcept>

namespace poz = pozdnyakov;

poz::Phonebook::iterator poz::Phonebook::begin()
{
  return this->book_.begin();
}

poz::Phonebook::iterator poz::Phonebook::end()
{
  return this->book_.end();
}

poz::Phonebook::const_iterator poz::Phonebook::cbegin()
{
  return this->book_.cbegin();
}

poz::Phonebook::const_iterator poz::Phonebook::cend()
{
  return this->book_.cend();
}

void poz::Phonebook::pushBack(value_type& val)
{
  return this->book_.push_back(val);
}

poz::Phonebook::iterator poz::Phonebook::insertBefore(const_iterator position, const value_type& val)
{
  return this->book_.insert(position, val);
}

poz::Phonebook::iterator poz::Phonebook::insertAfter(const_iterator position, const value_type& val)
{
  if (position == this->end())
  {
    throw std::invalid_argument("Iterator out of range");
  }
  return this->book_.insert(std::next(position), val);
}

poz::Phonebook::iterator poz::Phonebook::erase(iterator it)
{
  return this->book_.erase(it);
}

void poz::Phonebook::replace(iterator it, value_type& val)
{
  *it = val;
}

size_t poz::Phonebook::size()
{
  return book_.size();
}

void poz::Phonebook::move(iterator it, int n)
{
  if (n < std::distance(this->end(), it))
  {
    throw std::invalid_argument("<INVALID STEP>");
  }
  it = book_.insert(std::next(it, n), *it);
  book_.erase(it);
}
