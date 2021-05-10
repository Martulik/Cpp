#include "Book.hpp"
#include <cassert>
#include "record_t.hpp"

namespace lab = ezerinia;

lab::Book::Book()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void lab::Book::add(const record_t &record)
{
  phoneBook_.pushBack(record);
  if (std::next(phoneBook_.begin()) == phoneBook_.end()) {
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void lab::Book::store(const std::string &oldMarkName, const std::string &newMarkName)
{
  const std::map< std::string, PhoneBook::const_iterator >::iterator &iter = bookmarks_.find(oldMarkName);
  assert(iter != bookmarks_.end());
  bookmarks_[newMarkName] = iter->second;
}

void lab::Book::insert(const posOfInsert position, const std::string &markName, record_t &record)
{
  const std::map< std::string, PhoneBook::const_iterator >::iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  if (iter->second == phoneBook_.end()) {
    add(record);
  }
  if (position == posOfInsert::before) {
    phoneBook_.add(iter->second, record);
  } else if (position == posOfInsert::after) {
    phoneBook_.add(std::next(iter->second), record);
  }
}

void lab::Book::deleteRecord(const std::string &markName)
{
  const std::map< std::string, PhoneBook::const_iterator >::iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  auto deleteIter = iter->second;
  for (auto &&bookmark: bookmarks_) {
    if (bookmark.second == deleteIter) {
      if (std::next(bookmark.second) == phoneBook_.end()) {
        bookmark.second = std::prev(deleteIter);
      } else {
        bookmark.second = std::next(deleteIter);
      }
    }
  }
  phoneBook_.remove(deleteIter);
}

void lab::Book::show(const std::string &markName, std::ostream &out) const
{
  const std::map< std::string, PhoneBook::const_iterator >::const_iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  assert(!phoneBook_.empty());
  out << *iter->second;
}

void lab::Book::move(const std::string &markName, int steps)
{
  const std::map< std::string, PhoneBook::const_iterator >::iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  iter->second = phoneBook_.move(iter->second, steps);
}

void lab::Book::move(const std::string &markName, const posOfMove position)
{
  const std::map< std::string, PhoneBook::const_iterator >::iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  if (position == posOfMove::first) {
    iter->second = phoneBook_.begin();
  } else if (position == posOfMove::last) {
    iter->second = std::prev(phoneBook_.end());
  }
}

bool lab::Book::containsBookmark(const std::string &bookmark) const
{
  const std::map< std::string, PhoneBook::const_iterator >::const_iterator &iter = bookmarks_.find(bookmark);
  if (iter == bookmarks_.end()) {
    return false;
  }
  return true;
}

bool lab::Book::empty() const
{
  return phoneBook_.empty();
}
