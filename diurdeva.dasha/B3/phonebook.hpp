#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include <string>
#include "record_t.hpp"

namespace diurdeva {
  class Phonebook {
  public:
    using list = std::list< record_t >;
    using iterator = list::iterator;

    void pushBack(const record_t &rec);
    bool empty() const;
    iterator begin();
    iterator end();
    iterator next(iterator) const;
    iterator prev(iterator) const;
    iterator insert(iterator, const record_t &rec);
    iterator remove(iterator);
    iterator replace(iterator iter, record_t &src);
    iterator move(iterator, int);

  private:
    list list_;
  };
}

#endif 
