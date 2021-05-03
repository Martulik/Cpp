#include "phone-book.hpp"
#include "iterator-advance.hpp"

namespace shilyaev {
  void PhoneBook::insertBefore(const std::string &bookmarkName, const PhoneBook::Entry &entry)
  {
    const Iterator iterator = bookmarks_.at(bookmarkName);
    if (entries_.empty()) {
      pushBack(entry);
    } else {
      entries_.insert(iterator, entry);
    }
  }

  void PhoneBook::insertAfter(const std::string &bookmarkName, const PhoneBook::Entry &entry)
  {
    const Iterator iterator = bookmarks_.at(bookmarkName);
    if (entries_.empty()) {
      pushBack(entry);
    } else {
      entries_.insert(std::next(iterator), entry);
    }
  }

  void PhoneBook::pushBack(const PhoneBook::Entry &entry)
  {
    entries_.push_back(entry);
    if (entries_.size() == 1) {
      for (auto &&bookmark: bookmarks_) {
        bookmark.second = std::prev(entries_.end());
      }
    }
  }

  void PhoneBook::erase(const std::string &bookmarkName)
  {
    const Iterator iteratorToErase = bookmarks_.at(bookmarkName);
    Iterator newIterator = entries_.erase(iteratorToErase);
    if (newIterator == entries_.end()) {
      --newIterator;
    }
    for (auto &&bookmark: bookmarks_) {
      if (bookmark.second == iteratorToErase) {
        bookmark.second = newIterator;
      }
    }
  }

  void PhoneBook::store(const std::string &bookmarkName, const std::string &newBookmarkName)
  {
    bookmarks_[newBookmarkName] = bookmarks_.at(bookmarkName);
  }

  PhoneBook::PhoneBook()
  {
    bookmarks_["current"];
  }

  boost::optional< PhoneBook::Entry > PhoneBook::getEntry(const std::string &bookmarkName) const
  {
    const Iterator bookmark = bookmarks_.at(bookmarkName);
    if (entries_.empty()) {
      return {};
    }
    return *bookmark;
  }

  void PhoneBook::move(const std::string &bookmarkName, int n)
  {
    if (entries_.empty()) {
      return;
    }
    Iterator &bookmark = bookmarks_.at(bookmarkName);
    bookmark = safeAdvance(bookmark, n, entries_.begin(), entries_.end());
  }

  void PhoneBook::moveFirst(const std::string &bookmarkName)
  {
    if (entries_.empty()) {
      return;
    }
    bookmarks_.at(bookmarkName) = entries_.begin();
  }

  void PhoneBook::moveLast(const std::string &bookmarkName)
  {
    if (entries_.empty()) {
      return;
    }
    bookmarks_.at(bookmarkName) = std::prev(entries_.end());
  }
}
