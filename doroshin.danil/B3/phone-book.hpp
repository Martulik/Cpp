#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iosfwd>
#include <utility>
#include <string>
#include <list>
#include <map>

namespace doroshin
{
  /* # About the 'current' bookmark
    The current bookmark is added on initialisation and provides access to
    the entries for immediate use.

    Upon initialisation it does not point to a valid entry (since there are none)
    and referencing it is illegal

    After any command that creates a new entry (add, insert before, insert after)
    it points to the newly created entry
  */
  class PhoneBook
  {
  public:
    using Number = unsigned long long;
    using Name = std::string;
    using Entry = std::pair< Number, Name >;

    explicit PhoneBook();

    void add(Entry);
    void store(const Name& from, const Name& to);
    void delete_contents(const Name& mark);
    void insert_before(const Name& mark, Entry);
    void insert_after(const Name& mark, Entry);

    void move_front(const Name& mark);
    void move_back(const Name& mark);
    void move(const Name& mark, int steps);

    Entry show(const Name& mark) const;
  private:
    using Iter = typename std::list< Entry >::iterator;
    std::list< Entry > entries_;
    std::map< Name, Iter > bookmarks_;
  };
}

#endif //PHONE_BOOK_HPP
