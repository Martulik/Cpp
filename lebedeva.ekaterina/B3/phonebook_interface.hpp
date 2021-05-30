#ifndef PHONEBOOK_INTERFACE_HPP
#define PHONEBOOK_INTERFACE_HPP
#include <map>
#include "phonebook.hpp"

namespace lebedeva
{
  class Interface
  {
  public:
    enum class Where { before, after };
    enum class Steps { first, last };
    using constIter = std::map< std::string, PhoneBook::constIter >::const_iterator;
    using Iter = std::map< std::string, PhoneBook::constIter >::iterator;
    using BookmarkMap = std::map< std::string, PhoneBook::constIter >;

    Interface();

    void add(const record_t& rec);
    void store(const std::string& markName, const std::string& newMarkName);
    void insert(Where pos, const std::string& markName, const record_t& rec);
    void deleteRec(const std::string& markName);
    void move(const std::string& markName, int steps);
    void move(const std::string& markName, Steps steps);

    bool empty() const;
    constIter find(const std::string& markName) const;
    constIter begin() const;
    constIter end() const;
  private:
    PhoneBook book_;
    BookmarkMap bookmarks_;
  };
}
#endif
