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

void fer::PhoneBook::pushBack(const data_t& PhoneNote)
{
  notes_.push_back(PhoneNote);
}

fer::const_iter fer::PhoneBook::deletNote(const_iter it)
{
  return notes_.erase(it);
}

fer::const_iter fer::PhoneBook::move(const_iter it, int steps) const
{
  if (steps < 0)
  {
    while (it != notes_.begin() && steps != 0)
    {
      --it;
      ++steps;
    }
  }
  else
  {
    while (it != --notes_.end() && steps != 0)
    {
      ++it;
      --steps;
    }
  }
  return it;
}

bool fer::PhoneBook::empty() const
{
  return notes_.empty();
}

size_t fer::PhoneBook::size() const
{
  return notes_.size();
}

fer::const_iter fer::PhoneBook::begin() const
{
  return notes_.cbegin();
}

fer::const_iter fer::PhoneBook::end() const
{
  return notes_.cend();
}
