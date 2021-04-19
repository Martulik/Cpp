#include "UserInterface.hpp"
#include <iostream>

const std::string invalidCommand = "<INVALID COMMAND>\n";
const std::string invalidBookmark = "<INVALID BOOKMARK>\n";
const std::string empty = "<EMPTY>\n";

namespace lab = ezerinia;

lab::UserInterface::UserInterface()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void lab::UserInterface::add(PhoneBook::data &record)
{
  phoneBook_.pushBack(record);
  if (std::next(phoneBook_.begin()) == phoneBook_.end()) {
    bookmarks_.clear();
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void lab::UserInterface::store(std::string &oldMarkName, std::string &newMarkName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(oldMarkName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidCommand;
  } else {
    bookmarks_[newMarkName] = iter->second;
  }
}

void lab::UserInterface::insert(const std::string &position, std::string &markName, PhoneBook::data &record)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidBookmark;
    return;
  }
  if (iter->second == phoneBook_.end()) {
    add(record);
  }
  if (position == "before") {
    phoneBook_.add(iter->second, record);
  } else {
    phoneBook_.add(std::next(iter->second), record);
  }
}

void lab::UserInterface::deleteRecord(std::string &markName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidCommand;
  } else {
    auto deleteIter = iter->second;
    for (std::map< std::string, PhoneBook::iterator >::iterator i = bookmarks_.begin(); i != bookmarks_.end(); i++) {
      if (i->second == deleteIter) {
        if (std::next(i->second) == phoneBook_.end()) {
          i->second = phoneBook_.movePrev(deleteIter);
        } else {
          i->second = phoneBook_.moveNext(deleteIter);
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
    std::cout << invalidBookmark;
  } else if (phoneBook_.empty()) {
    std::cout << empty;
  } else {
    phoneBook_.show(iter->second);
  }
}

void lab::UserInterface::move(std::string &markName, int steps)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidBookmark;
  } else {
    iter->second = phoneBook_.move(iter->second, steps);
  }
}

void lab::UserInterface::move(std::string &markName, const std::string &position)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidBookmark;
  } else if (position == "first") {
    iter->second = phoneBook_.begin();
  } else {
    iter->second = phoneBook_.movePrev(phoneBook_.end());
  }
}
