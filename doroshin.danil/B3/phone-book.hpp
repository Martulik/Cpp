#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <list>
#include <map>
#include "entry.hpp"

namespace doroshin
{
  class PhoneBook
  {
  public:
    explicit PhoneBook();

    void add(Entry);
    void store(const std::string& from, const std::string& to);
    void delete_contents(const std::string& mark);
    void insert_before(const std::string& mark, Entry);
    void insert_after(const std::string& mark, Entry);

    void move_front(const std::string& mark);
    void move_back(const std::string& mark);
    void move(const std::string& mark, int steps);

    Entry show(const std::string& mark) const;
  private:
    using Iter = typename std::list< Entry >::const_iterator;
    std::list< Entry > entries_;
    std::map< std::string, Iter > bookmarks_;

    void update_current();
  };
}

#endif //PHONE_BOOK_HPP
