#include "book.hpp"

namespace fer = ferapontov;

void fer::PhoneBook::insertPrev(const_iter it, const data_t& phoneNote)
{
  notes_.insert(it, phoneNote);
}

void fer::PhoneBook::insertNext(const_iter it, const data_t& phoneNote)
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

fer::const_iter fer::PhoneBook::begin()
{
  return notes_.cbegin();
}

fer::const_iter fer::PhoneBook::end()
{
  return notes_.cend();
}
