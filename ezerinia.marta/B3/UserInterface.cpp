#include "UserInterface.hpp"
#include <iostream>
#include "tools.hpp"

namespace lab = ezerinia;

lab::UserInterface::UserInterface()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void lab::UserInterface::add(record_t &record)
{
  phoneBook_.pushBack(record);
  if (std::next(phoneBook_.begin()) == phoneBook_.end()) {
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void lab::UserInterface::store(std::string &oldMarkName, std::string &newMarkName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(oldMarkName);
  if (iter == bookmarks_.end()) {
    invalidCommand(std::cout);
  } else {
    bookmarks_[newMarkName] = iter->second;
  }
}

void lab::UserInterface::insert(posOfInsert position, std::string &markName, record_t &record)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    invalidBookmark(std::cout);
    return;
  }
  if (iter->second == phoneBook_.end()) {
    add(record);
  }
  if (position == posOfInsert::before) {
    phoneBook_.add(iter->second, record);
  } else if (position == posOfInsert::after) {
    phoneBook_.add(std::next(iter->second), record);
  }
}

void lab::UserInterface::deleteRecord(std::string &markName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    invalidCommand(std::cout);
  } else {
    auto deleteIter = iter->second;
    for (auto i = bookmarks_.begin(); i != bookmarks_.end(); i++) {
      if (i->second == deleteIter) {
        if (std::next(i->second) == phoneBook_.end()) {
          i->second = std::prev(deleteIter);
          //i->second = phoneBook_.movePrev(deleteIter);
        } else {
          i->second = std::next(deleteIter);
          //i->second = phoneBook_.moveNext(deleteIter);
        }
      }
    }
    phoneBook_.remove(deleteIter);
  }
}

void lab::UserInterface::show(std::string &markName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    invalidBookmark(std::cout);
  } else if (phoneBook_.empty()) {
    empty(std::cout);
  } else {
    std::cout << &iter->second;
    //phoneBook_.show(iter->second);
  }
}

void lab::UserInterface::move(std::string &markName, int steps)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    invalidBookmark(std::cout);
  } else {
    iter->second = phoneBook_.move(iter->second, steps);
  }
}

void lab::UserInterface::move(std::string &markName, posOfMove position)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    invalidBookmark(std::cout);
  } else if (position == posOfMove::first) {
    iter->second = phoneBook_.begin();
  } else if (position == posOfMove::last) {
    iter->second = std::prev(phoneBook_.end());
    //iter->second = phoneBook_.movePrev(phoneBook_.end());
  }
}
