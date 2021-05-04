#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <map>
#include <string>
#include <boost/optional/optional.hpp>

namespace shilyaev {
  class PhoneBook {
  public:
    struct Entry {
      std::string number;
      std::string name;
    };
    PhoneBook();
    boost::optional< Entry > getEntry(const std::string &bookmarkName) const;
    void insertBefore(const std::string &bookmarkName, const Entry& entry);
    void insertAfter(const std::string &bookmarkName, const Entry& entry);
    void pushBack(const Entry& entry);
    void store(const std::string &bookmarkName, const std::string &newBookmarkName);
    void erase(const std::string &bookmarkName);
    void move(const std::string &bookmarkName, int n);
    void moveFirst(const std::string &bookmarkName);
    void moveLast(const std::string &bookmarkName);
  private:
    using Iterator = std::list< Entry >::iterator;
    std::list< Entry > entries_;
    std::map< std::string, Iterator > bookmarks_;
  };
}

#endif
