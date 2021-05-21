#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include <string>
#include "record_t.hpp"

namespace diurdeva {
  class Phonebook {
  public:
    using list = std::list< record_t >;
    using const_iterator = std::list< record_t >::const_iterator;
    void pushBack(const record_t &rec);
    bool empty() const;

    const_iterator begin() const;
    const_iterator end() const;
    const_iterator insert(const_iterator, const record_t &rec);
    const_iterator remove(const_iterator);
    const_iterator move(const_iterator, const int);

  private:
    list list_;
  };
}

#endif
