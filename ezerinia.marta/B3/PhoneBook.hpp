#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include "record_t.hpp"

namespace ezerinia {
  class PhoneBook {
  public:
    using const_iterator = std::list< record_t >::const_iterator;
    bool empty() const;
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator add(const_iterator iter, const record_t &src);
    const_iterator move(const_iterator iter, int step);
    const_iterator remove(const_iterator iter);
    void pushBack(const record_t &src);
  private:
    std::list< record_t > list_;
  };
}
#endif
