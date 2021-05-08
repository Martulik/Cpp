#include "phonebookInterface.hpp"

#include <algorithm>
#include <iostream>
#include "comands.hpp"

diurdeva::PhonebookManager::PhonebookManager() {
  bookmarks_["current"] = records_.begin();
}

void diurdeva::PhonebookManager::add(const record_t& rec)
{
  records_.pushBack(rec);
  if (std::next(records_.begin()) == records_.end()) {
    bookmarks_["current"] = records_.begin();
  }
}

void diurdeva::PhonebookManager::store(const std::string& bookmark, const std::string& newBookmark)
{
  const std::map<std::string, Phonebook::iterator>::iterator &iter = bookmarks_.find(bookmark);
  bookmarks_.emplace(newBookmark, iter->second);
}

void diurdeva::PhonebookManager::insert(InsertPosition position, const std::string& bookmark, record_t& rec)
{
  const std::map<std::string, Phonebook::iterator>::iterator& iter = bookmarks_.find(bookmark);
  if (iter->second == records_.end()) {
    add(rec);
  }
  if (position == InsertPosition::AFTER) {
    records_.insert(std::next(iter->second), rec);
  }
  else {
    records_.insert(iter->second, rec);
  }
}

void diurdeva::PhonebookManager::deleteNote(const std::string& bookmark)
{
  const std::map<std::string, Phonebook::iterator>::iterator& iter = bookmarks_.find(bookmark);
  auto eraseIter = iter->second;
  for (auto i = bookmarks_.begin(); i != bookmarks_.end(); ++i) {
    if (i->second == eraseIter) {
      if (std::next(i->second) == records_.end()) {
        i->second = std::prev(eraseIter);
      }
      else {
         i->second = std::next(eraseIter);
      }
    }
  }
  records_.remove(eraseIter);
}

void diurdeva::PhonebookManager::show(const std::string& bookmark)
{
  const std::map<std::string, Phonebook::iterator>::iterator& iter = bookmarks_.find(bookmark);
  if (records_.empty()) {
    empty(std::cout);
  }
  std::cout << *iter->second;
}

void diurdeva::PhonebookManager::move(const std::string& bookmark, int n)
{
  const std::map<std::string, Phonebook::iterator>::iterator& iter = bookmarks_.find(bookmark);
  iter->second = records_.move(iter->second, n);
}

void diurdeva::PhonebookManager::move(const std::string& bookmark, MovePosition loc)
{
  const std::map<std::string, Phonebook::iterator>::iterator& iter = bookmarks_.find(bookmark);
  if (loc == MovePosition::FIRST) {
    iter->second = records_.begin();
  }

  if (loc == MovePosition::LAST) {
    iter->second = records_.prev(records_.end());
  } 
}

bool diurdeva::PhonebookManager::containsBookmark(const std::string& bookmark)
{
  return (bookmarks_.find(bookmark) != bookmarks_.end() ? 1 : 0);
}
