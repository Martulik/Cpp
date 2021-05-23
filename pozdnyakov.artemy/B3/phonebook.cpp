#include "phonebook.hpp"
#include <stdexcept>

namespace poz = pozdnyakov;

poz::Phonebook::const_iterator poz::Phonebook::cbegin() const
{
  return this->book_.cbegin();
}

poz::Phonebook::const_iterator poz::Phonebook::cend() const
{
  return this->book_.cend();
}

void poz::Phonebook::pushBack(value_type& val)
{
  return this->book_.push_back(val);
}

poz::Phonebook::const_iterator poz::Phonebook::insert(const_iterator position, const value_type& val)
{
  return this->book_.insert(position, val);
}

poz::Phonebook::const_iterator poz::Phonebook::erase(const_iterator it)
{
  return this->book_.erase(it);
}

size_t poz::Phonebook::size() const
{
  return book_.size();
}

poz::Phonebook::iterator poz::Phonebook::begin()
{
  return this->book_.begin();
}

poz::Phonebook::iterator poz::Phonebook::end()
{
  return this->book_.end();
}
