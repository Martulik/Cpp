#include "phone-book.hpp"

using PB = pochernin::PhoneBook;

void PB::add(const Note& note)
{
  data_.push_back(note);
}

PB::constIterator PB::begin()
{
  return data_.cbegin();
}

PB::constIterator PB::end()
{
  return data_.cend();
}
