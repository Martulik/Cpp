#include "book.hpp"

namespace fer = ferapontov;

fer::data_t fer::PhoneBook::showCurrent(std::ostream out, iter it) const
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

fer::iter fer::PhoneBook::move(iter it, int steps) const
{
  //нужна будет проверка
  for (int i = 0; i < steps; i++)
  {
    it++;
  }
  return it;
}

fer::citer fer::PhoneBook::begin() const
{
  return notes_.cbegin();
}

fer::citer fer::PhoneBook::end() const
{
  return notes_.cend();
}
