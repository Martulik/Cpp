#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <map>
#include <string>

namespace shilyaev {
  class PhoneBook {
  public:
    struct Entry {
      std::string number;
      std::string name;
    };
    PhoneBook();
    Entry getEntry(const std::string &bookmarkName) const;
    void insertBefore(const std::string &bookmarkName, const Entry& entry);
    void insertAfter(const std::string &bookmarkName, const Entry& entry);
    void pushBack(const Entry& entry);
    void store(const std::string &bookmarkName, const std::string &newBookmarkName);
    void erase(const std::string &bookmarkName);
    void move(const std::string &bookmarkName, int n);
    void moveFirst(const std::string &bookmarkName);
    void moveLast(const std::string &bookmarkName);
  private:
    using EntriesContainer = std::list< Entry >;
    using Iterator = EntriesContainer::const_iterator;
    EntriesContainer entries_;
    std::map< std::string, Iterator > bookmarks_;
    Iterator &getBookmark(const std::string &bookmarkName);
    const Iterator &getBookmark(const std::string &bookmarkName) const;
  };

  class EmptyException: public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class NoBookmarkException: public std::exception {
  public:
    const char *what() const noexcept override;
  };
}

#endif
