#include "PhoneBook.hpp"
#include <iostream>

bool PhoneBook::empty()
{
  return listPhoneBook_.empty();
}

PhoneBook::iterator PhoneBook::begin()
{
  return listPhoneBook_.begin();
}

PhoneBook::iterator PhoneBook::end()
{
  return listPhoneBook_.end();
}

PhoneBook::iterator PhoneBook::add(iterator iter, data &src)
{
  return listPhoneBook_.insert(iter, src);
}

PhoneBook::iterator PhoneBook::move(iterator iter, int step)
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

PhoneBook::iterator PhoneBook::moveNext(iterator iter)
{
  return ++iter;
}

PhoneBook::iterator PhoneBook::movePrev(iterator iter)
{
  return --iter;
}

PhoneBook::iterator PhoneBook::remove(iterator iter)
{
  return listPhoneBook_.erase(iter);
}

void PhoneBook::show(iterator iter)
{
  std::cout << (*iter).first << " " << (*iter).second << "\n";
}

PhoneBook::iterator PhoneBook::replace(iterator iter, data &src)
{
  *iter = src;
  return iter;
}

void PhoneBook::pushBack(data &src)
{
  return listPhoneBook_.push_back(src);
}
