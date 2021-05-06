#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include "record_t.hpp"

namespace ezerinia {
  class PhoneBook {
  public:
    using iterator = std::list< record_t >::iterator;
    bool empty();
    iterator begin();
    iterator end();
    iterator add(iterator iter, record_t &src);
    iterator move(iterator iter, int step);
    iterator remove(iterator iter);
    iterator replace(iterator iter, record_t &src);
    void pushBack(record_t &src);
  private:
    std::list< record_t > list_;
  };
}
#endif
