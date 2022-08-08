#include "Book.hpp"
#include <cassert>
#include "record_t.hpp"

namespace lab = ezerinia;

lab::Book::Book():
  phoneBook_(),
  bookmarks_({{"current", phoneBook_.begin()}})
{
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
  const lab::Book::const_iterator &iter = bookmarks_.find(oldMarkName);
  assert(iter != bookmarks_.end());
  bookmarks_[newMarkName] = iter->second;
}

void lab::Book::insert(const std::string &bookmark, record_t &record, posOfInsert position)
{
  const lab::Book::const_iterator &iter = bookmarks_.find(bookmark);
  assert(iter != bookmarks_.end());
  if (iter->second == phoneBook_.end()) {
    add(record);
  }
  if (position == posOfInsert::before) {
    phoneBook_.add(record, iter->second);
  } else if (position == posOfInsert::after) {
    phoneBook_.add(record, std::next(iter->second));
  }
}

void lab::Book::deleteRecord(const std::string &markName)
{
  const lab::Book::const_iterator &iter = bookmarks_.find(markName);
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

void lab::Book::move(const std::string &markName, int steps)
{
  const lab::Book::iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  iter->second = phoneBook_.move(iter->second, steps);
}

void lab::Book::move(const std::string &markName, const posOfMove position)
{
  const lab::Book::iterator &iter = bookmarks_.find(markName);
  assert(iter != bookmarks_.end());
  if (position == posOfMove::first) {
    iter->second = phoneBook_.begin();
  } else if (position == posOfMove::last) {
    iter->second = std::prev(phoneBook_.end());
  }
}

bool lab::Book::containsBookmark(const std::string &bookmark) const
{
  const lab::Book::const_iterator &iter = bookmarks_.find(bookmark);
  if (iter == bookmarks_.end()) {
    return false;
  }
  return true;
}

bool lab::Book::empty() const
{
  return phoneBook_.empty();
}

lab::Book::const_iterator lab::Book::findBookmark(const std::string &bookmark) const
{
  return bookmarks_.find(bookmark);
}
