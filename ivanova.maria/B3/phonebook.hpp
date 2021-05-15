#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iosfwd>
#include <string>
#include <list>

#include "record.hpp"

namespace ivanova
{
  class PhoneBook
  {
  public:
    using iter = std::list< Record >::const_iterator;
    iter begin() const;
    iter end() const;
    void add(const Record &record);
    void insert(const iter userIt, const Record &record);
    void erase(const iter iter);
    iter moveOnStep(iter iter, int step) const;
    bool isEmpty() const;

  private:
    using ListOfRecord = std::list< Record >;
    ListOfRecord list_;
  };
}
#endif
