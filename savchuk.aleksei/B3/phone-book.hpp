#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <cstdlib>

#include "contact.hpp"

namespace savchuk
{
  class PhoneBook
  {
    public:
      using iterator = std::list< contact_t >::iterator;

      const contact_t& show(iterator it) const;
      iterator moveNext(iterator it);
      iterator movePrev(iterator it);
      iterator add(iterator it, const contact_t& src);
      iterator replace(iterator it, const contact_t& src);
      iterator add(const contact_t& src);
      iterator move(iterator it, int steps);
      iterator remove(iterator it);
      bool empty() const;
      size_t size() const;
      iterator begin();
      iterator end();

    private:
      std::list< contact_t > data_;
  };
}

#endif
