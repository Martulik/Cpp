#include "UserInterface.hpp"
#include <iostream>

const std::string invalidCommand = "<INVALID COMMAND>\n";
const std::string invalidBookmark = "<INVALID BOOKMARK>\n";
const std::string empty = "<EMPTY>\n";

UserInterface::UserInterface()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void UserInterface::add(PhoneBook::data &record)
{
  phoneBook_.pushBack(record);
  if (std::next(phoneBook_.begin()) == phoneBook_.end()) {
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void UserInterface::store(std::string &markName, std::string &newMarkName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end()) {
    bookmarks_[newMarkName] = iter->second;
    return;
  }
  std::cout << invalidCommand;
}

void UserInterface::insert(const std::string &position, std::string &markName, PhoneBook::data &record)
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
    phoneBook_.insert(iter->second, record);
  } else {
    phoneBook_.insert(std::next(iter->second), record);
  }
}

void UserInterface::deleteRecord(std::string &markName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidCommand;
    return;
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

void UserInterface::show(std::string &markName)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter != bookmarks_.end()) {
    if (phoneBook_.empty()) {
      std::cout << empty;
      return;
    }
    return phoneBook_.show(iter->second);
  }
  std::cout << invalidBookmark;
}

void UserInterface::move(std::string &markName, int steps)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidBookmark;
    return;
  }
  iter->second = phoneBook_.move(iter->second, steps);
}

void UserInterface::move(std::string &markName, const std::string &movePosition)
{
  const std::map< std::string, PhoneBook::iterator >::iterator &iter = bookmarks_.find(markName);
  if (iter == bookmarks_.end()) {
    std::cout << invalidBookmark;
    return;
  }
  if (movePosition == "first") {
    iter->second = phoneBook_.begin();
  } else {
    iter->second = phoneBook_.movePrev(phoneBook_.end());
  }
}
