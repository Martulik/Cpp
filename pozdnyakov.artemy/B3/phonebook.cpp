#include "phonebook.hpp"
#include <stdexcept>

namespace poz = pozdnyakov;

typedef poz::Phonebook::iterator poz::Phonebook::begin()
{
  return this->book_->begin();
}

typedef poz::Phonebook::iterator poz::Phonebook::end()
{
  return this->book_->end();
}

typedef poz::Phonebook::const_iterator poz::Phonebook::cbegin()
{
  return this->book_->cbegin();
}

typedef poz::Phonebook::const_iterator poz::Phonebook::cend()
{
  return this->book_->cend();
}

void poz::Phonebook::pushBack(value_type& val)
{
  return this->book_->push_back(val);
}

typedef poz::Phonebook::iterator poz::Phonebook::insertBefore(const_iterator position, const value_type& val)
{
  return this->book_->insert(position, val);
}

typedef poz::Phonebook::iterator poz::Phonebook::insertAfter(const_iterator position, const value_type& val)
{
  if (position == this->end())
  {
    throw std::invalid_argument("Iterator out of range");
  }
  return this->book_->insert(position + 1, val);
}

typedef poz::Phonebook::iterator poz::Phonebook::erase(poz::Phonebook::iterator it)
{
  return this->book_->erase(it);
}

void poz::Phonebook::replace(poz::Phonebook::iterator it, poz::Phonebook::value_type& val)
{
  *it = val;
}

void poz::Phonebook::move(typedef Phonebook::iterator it, int n)
{
  if (n < this->end() - it)
  {
    return;
  }
  it = this->insert(it + n; *it);
  this->erase(it);
}
