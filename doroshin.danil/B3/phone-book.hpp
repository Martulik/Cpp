#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <utility>
#include <exception>
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
