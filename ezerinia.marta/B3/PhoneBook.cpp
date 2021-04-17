#include "PhoneBook.hpp"
#include <iostream>

namespace lab = ezerinia;

bool lab::PhoneBook::empty()
{
  return listPhoneBook_.empty();
}

lab::PhoneBook::iterator lab::PhoneBook::begin()
{
  return listPhoneBook_.begin();
}

lab::PhoneBook::iterator lab::PhoneBook::end()
{
  return listPhoneBook_.end();
}

lab::PhoneBook::iterator lab::PhoneBook::add(iterator iter, data &src)
{
  return listPhoneBook_.insert(iter, src);
}

lab::PhoneBook::iterator lab::PhoneBook::move(iterator iter, int step)
{
  int counter = 0;
  if (step >= 0) {
    while ((std::next(iter) != listPhoneBook_.end()) && (counter != step)) {
      ++iter;
      ++counter;
    }
  } else {
    while ((iter != listPhoneBook_.begin()) && (counter != step)) {
      --iter;
      --counter;
    }
  }
  return iter;
}

lab::PhoneBook::iterator lab::PhoneBook::moveNext(iterator iter)
{
  return ++iter;
}

lab::PhoneBook::iterator lab::PhoneBook::movePrev(iterator iter)
{
  return --iter;
}

lab::PhoneBook::iterator lab::PhoneBook::remove(iterator iter)
{
  return listPhoneBook_.erase(iter);
}

void lab::PhoneBook::show(iterator iter)
{
  std::cout << (*iter).first << " " << (*iter).second << "\n";
}

lab::PhoneBook::iterator lab::PhoneBook::replace(iterator iter, data &src)
{
  *iter = src;
  return iter;
}

void lab::PhoneBook::pushBack(data &src)
{
  return listPhoneBook_.push_back(src);
}
