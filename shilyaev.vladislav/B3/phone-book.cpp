#include "phone-book.hpp"
#include "iterator-advance.hpp"

namespace shilyaev {
  void PhoneBook::insertBefore(const std::string &bookmarkName, const PhoneBook::Entry &entry)
  {
    const Iterator iterator = getBookmark(bookmarkName);
    if (entries_.empty()) {
      pushBack(entry);
    } else {
      entries_.insert(iterator, entry);
    }
  }

  void PhoneBook::insertAfter(const std::string &bookmarkName, const PhoneBook::Entry &entry)
  {
    const Iterator iterator = getBookmark(bookmarkName);
    if (entries_.empty()) {
      pushBack(entry);
    } else {
      entries_.insert(std::next(iterator), entry);
    }
  }

  void PhoneBook::pushBack(const PhoneBook::Entry &entry)
  {
    bool areBookmarksInvalid = entries_.empty();
    entries_.push_back(entry);
    if (areBookmarksInvalid) {
      for (auto &&bookmark: bookmarks_) {
        bookmark.second = entries_.begin();
      }
    }
  }

  void PhoneBook::erase(const std::string &bookmarkName)
  {
    const Iterator iteratorToErase = getBookmark(bookmarkName);
    Iterator newIterator = entries_.erase(iteratorToErase);
    if (entries_.empty()) {
      return;
    }
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
    bookmarks_[newBookmarkName] = getBookmark(bookmarkName);
  }

  PhoneBook::PhoneBook():
    entries_(),
    bookmarks_({{"current", Iterator()}})
  {
  }

  PhoneBook::Entry PhoneBook::getEntry(const std::string &bookmarkName) const
  {
    const Iterator bookmark = getBookmark(bookmarkName);
    if (entries_.empty()) {
      throw EmptyException();
    }
    return *bookmark;
  }

  void PhoneBook::move(const std::string &bookmarkName, int n)
  {
    if (entries_.empty()) {
      return;
    }
    Iterator &bookmark = getBookmark(bookmarkName);
    bookmark = safeAdvance(bookmark, n, entries_.begin(), entries_.end());
  }

  void PhoneBook::moveFirst(const std::string &bookmarkName)
  {
    if (entries_.empty()) {
      return;
    }
    getBookmark(bookmarkName) = entries_.begin();
  }

  void PhoneBook::moveLast(const std::string &bookmarkName)
  {
    if (entries_.empty()) {
      return;
    }
    getBookmark(bookmarkName) = std::prev(entries_.end());
  }

  PhoneBook::Iterator &PhoneBook::getBookmark(const std::string &bookmarkName)
  {
    try {
      return bookmarks_.at(bookmarkName);
    } catch (const std::out_of_range &) {
      throw NoBookmarkException();
    }
  }

  const PhoneBook::Iterator &PhoneBook::getBookmark(const std::string &bookmarkName) const
  {
    try {
      return bookmarks_.at(bookmarkName);
    } catch (const std::out_of_range &) {
      throw NoBookmarkException();
    }
  }

  const char *EmptyException::what() const noexcept
  {
    return "PhoneBook empty";
  }

  const char *NoBookmarkException::what() const noexcept
  {
    return "No such bookmark";
  }
}
