#ifndef BOOK_HPP
#define BOOK_HPP

#include <utility>
#include <list>
#include "data.hpp"

namespace ferapontov
{
  using iter = std::list< data_t >::iterator;
  using const_iter = std::list< data_t >::const_iterator;
  class PhoneBook
  {
    public:
      void insertPrev(const_iter it, const data_t& phoneNote);
      void insertNext(const_iter it, const data_t& phoneNote);

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
