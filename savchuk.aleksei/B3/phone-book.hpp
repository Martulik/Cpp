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
      using const_iterator = std::list< contact_t >::const_iterator;

      const_iterator add(const_iterator it, const contact_t& contact);
      const_iterator replace(const_iterator it, const contact_t& contact);
      const_iterator add(const contact_t& contact);
      const_iterator move(const_iterator it, int steps) const;
      iterator remove(const_iterator it);
      bool empty() const;
      size_t size() const;
      const_iterator cbegin() const;
      const_iterator cend() const;

    private:
      std::list< contact_t > data_;
  };
}

#endif
