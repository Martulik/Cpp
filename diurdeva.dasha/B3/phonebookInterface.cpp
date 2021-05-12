#include "phonebookInterface.hpp"

#include <algorithm>
#include <cassert>
#include "comands.hpp"

diurdeva::PhonebookManager::PhonebookManager():
  records_(),
  bookmarks_({ {"current", records_.begin()} })
{}

void diurdeva::PhonebookManager::add(const record_t &rec)
{
  records_.pushBack(rec);
  if (std::next(records_.begin()) == records_.end()) {
    bookmarks_["current"] = records_.begin();
  }
}

void diurdeva::PhonebookManager::store(const std::string &bookmark, const std::string &newBookmark)
{
  const std::map< std::string, Phonebook::const_iterator >::iterator &iter = bookmarks_.find(bookmark);
  assert(iter != bookmarks_.end());
  bookmarks_.emplace(newBookmark, iter->second);
}

void diurdeva::PhonebookManager::insert(InsertPosition position, const std::string &bookmark, record_t &rec)
{
  const std::map< std::string, Phonebook::const_iterator >::iterator &iter = bookmarks_.find(bookmark);
  assert(iter != bookmarks_.end());
  if (iter->second == records_.end()) {
    add(rec);
  }
  if (position == InsertPosition::AFTER) {
    records_.insert(std::next(iter->second), rec);
  } else {
    records_.insert(iter->second, rec);
  }
}

void diurdeva::PhonebookManager::deleteNote(const std::string &bookmark)
{
  const std::map< std::string, Phonebook::const_iterator >::iterator &iter = bookmarks_.find(bookmark);
  assert(iter != bookmarks_.end());
  auto eraseIter = iter->second;
  for (auto i = bookmarks_.begin(); i != bookmarks_.end(); ++i) {
    if (i->second == eraseIter) {
      if (std::next(i->second) == records_.end()) {
        i->second = std::prev(eraseIter);
      } else {
        i->second = std::next(eraseIter);
      }
    }
  }
  records_.remove(eraseIter);
}

void diurdeva::PhonebookManager::move(const std::string &bookmark, int n)
{
  const std::map< std::string, Phonebook::const_iterator >::iterator &iter = bookmarks_.find(bookmark);
  assert(iter != bookmarks_.end());
  iter->second = records_.move(iter->second, n);
}

void diurdeva::PhonebookManager::move(const std::string &bookmark, MovePosition loc)
{
  const std::map< std::string, Phonebook::const_iterator >::iterator &iter = bookmarks_.find(bookmark);
  assert(iter != bookmarks_.end());
  if (loc == MovePosition::FIRST) {
    iter->second = records_.begin();
  }

  if (loc == MovePosition::LAST) {
    iter->second = std::prev(records_.end());
  }
}

bool diurdeva::PhonebookManager::containsBookmark(const std::string &bookmark) const
{
  const std::map< std::string, Phonebook::const_iterator >::const_iterator& iter = bookmarks_.find(bookmark);
  return ((iter != bookmarks_.end()) ? 1 : 0);
}

bool diurdeva::PhonebookManager::empty() const
{
  return records_.empty();
}

diurdeva::PhonebookManager::const_iterator diurdeva::PhonebookManager::findBookmark(const std::string& mark) const
{
  return bookmarks_.find(mark);
}