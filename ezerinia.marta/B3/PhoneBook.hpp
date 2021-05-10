#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include "record_t.hpp"

namespace ezerinia {
  class PhoneBook {
  public:
    using iterator = std::list< record_t >::iterator;
    bool empty() const;
    iterator begin();
    iterator end();
    iterator add(iterator iter, const record_t &src);
    iterator move(iterator iter, int step);
    iterator remove(iterator iter);
    void pushBack(const record_t &src);
  private:
    std::list< record_t > list_;
  };
}
#endif
