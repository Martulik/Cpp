#include "PhoneBook.hpp"

namespace lab = ezerinia;

bool lab::PhoneBook::empty() const
{
  return list_.empty();
}

lab::PhoneBook::iterator lab::PhoneBook::begin()
{
  return list_.begin();
}

lab::PhoneBook::iterator lab::PhoneBook::end()
{
  return list_.end();
}

lab::PhoneBook::iterator lab::PhoneBook::add(const iterator iter, const record_t &src)
{
  return list_.insert(iter, src);
}

lab::PhoneBook::iterator lab::PhoneBook::move(iterator iter, int step)
{
  int counter = 0;
  if (step >= 0) {
    while ((std::next(iter) != list_.end()) && (counter != step)) {
      ++iter;
      ++counter;
    }
  } else {
    while ((iter != list_.begin()) && (counter != step)) {
      --iter;
      --counter;
    }
  }
  return iter;
}

lab::PhoneBook::iterator lab::PhoneBook::remove(const iterator iter)
{
  return list_.erase(iter);
}

void lab::PhoneBook::pushBack(const record_t &src)
{
  return list_.push_back(src);
}
