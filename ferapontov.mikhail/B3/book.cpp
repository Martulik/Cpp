#include "book.hpp"

namespace fer = ferapontov;

fer::data_t& fer::PhoneBook::showCurrent(const iter it) const
{
  return *it;
}

void fer::PhoneBook::insertPrev(iter it, const data_t& phoneNote)
{
  notes_.insert(it, phoneNote);
}

void fer::PhoneBook::insertNext(iter it, const data_t& phoneNote)
{
  notes_.insert(++it, phoneNote);
}

void fer::PhoneBook::pushBack(data_t& PhoneNote)
{
  notes_.push_back(PhoneNote);
}

bool fer::PhoneBook::empty() const
{
  return notes_.empty();
}

fer::iter fer::PhoneBook::begin()
{
  return notes_.begin();
}

fer::iter fer::PhoneBook::end()
{
  return notes_.end();
}
