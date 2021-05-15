#ifndef BOOK_HPP
#define BOOK_HPP

#include <utility>
#include <string>
#include <list>
#include "data.hpp"

namespace ferapontov
{
  using iter = std::list< data_t >::iterator;
  using const_iter = std::list< data_t >::const_iterator;
  class PhoneBook
  {
    public:
      data_t& showCurrent(const iter it) const;

      void insertPrev(iter it, const data_t& phoneNote);
      void insertNext(iter it, const data_t& phoneNote);

      void replace(iter it, const data_t& phoneNote);

      void pushBack(data_t& PhoneNote);

      bool empty() const;

      const_iter begin();
      const_iter end();
    private:
      std::list< data_t > notes_;
  };
}

#endif
