#ifndef BOOK_HPP
#define BOOK_HPP

#include <utility>
#include <string>
#include <list>
#include "data.hpp"

namespace ferapontov
{
  using iter = std::list< data_t >::iterator;
  using citer = std::list< data_t >::const_iterator;
  class PhoneBook
  {
    public:
      data_t showCurrent(std::ostream out, iter it) const;

      void insertPrev(iter it, const data_t& phoneNote);
      void insertNext(iter it, const data_t& phoneNote);

      void replace(const data_t& phoneNote);

      void pushBack(data_t& PhoneNote);

      iter move(iter it, int steps) const;
      citer begin() const;
      citer end() const;
    private:
      std::list< data_t > notes_;
  };
}

#endif
