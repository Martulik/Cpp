#include "PhoneBook.hpp"

namespace lab = ezerinia;

bool lab::PhoneBook::empty() const
{
  return list_.empty();
}

lab::PhoneBook::const_iterator lab::PhoneBook::begin() const
{
  return list_.begin();
}

lab::PhoneBook::const_iterator lab::PhoneBook::end() const
{
  return list_.end();
}

lab::PhoneBook::const_iterator lab::PhoneBook::add(const record_t &src, const_iterator iter)
{
  return list_.insert(iter, src);
}

lab::PhoneBook::const_iterator lab::PhoneBook::move(const_iterator iter, const int step)
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

lab::PhoneBook::const_iterator lab::PhoneBook::remove(const_iterator iter)
{
  return list_.erase(iter);
}

void lab::PhoneBook::pushBack(const record_t &src)
{
  return list_.push_back(src);
}
