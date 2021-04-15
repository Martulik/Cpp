#include "PhoneBook.hpp"
#include <iostream>

bool PhoneBook::empty()
{
  return listPhoneBookEntry.empty();
}

PhoneBook::iterator PhoneBook::begin()
{
  return listPhoneBookEntry.begin();
}

PhoneBook::iterator PhoneBook::end()
{
  return listPhoneBookEntry.end();
}

PhoneBook::iterator PhoneBook::insert(iterator iter, data &src)
{
  return listPhoneBookEntry.insert(iter, src);
}

PhoneBook::iterator PhoneBook::move(iterator iter, int step)
{
  int counter = 0;
  if (step >= 0) {
    while ((std::next(iter) != listPhoneBookEntry.end()) && (counter != step)) {
      ++iter;
      ++counter;
    }
  } else {
    while ((iter != listPhoneBookEntry.begin()) && (counter != step)) {
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
  return listPhoneBookEntry.erase(iter);
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
  return listPhoneBookEntry.push_back(src);
}
