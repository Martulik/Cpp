#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iosfwd>
#include <utility>
#include <string>
#include <list>
#include <map>

namespace doroshin
{
  class PhoneBook
  {
  public:
    using Number = unsigned long long;
    using Name = std::string;
    using Entry = std::pair< Number, Name >;

    explicit PhoneBook();

    void add(Entry);
    void store(const Name& from, const Name& to);
    void insert_before(const Name& mark, Entry);
    void insert_after(const Name& mark, Entry);
    void delete_contents(const Name& mark);
    Entry show(const Name& mark) const;
    void move_front(const Name& mark);
    void move_back(const Name& mark);
    void move(const Name& mark, int steps);
  private:
    using Iter = typename std::list< Entry >::iterator;
    // using Bookmark = std::pair< Name, Iter >;
    std::list< Entry > entries_;
    std::map< Name, Iter > bookmarks_;

    // Iter getMark(const Name&);
  };
}

#endif //PHONE_BOOK_HPP
