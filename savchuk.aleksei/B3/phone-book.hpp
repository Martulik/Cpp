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

      const contact_t& show(const_iterator it) const;
      iterator add(const_iterator it, const contact_t& contact);
      iterator replace(iterator it, const contact_t& contact);
      iterator add(const contact_t& contact);
      iterator move(iterator it, int steps);
      iterator remove(const_iterator it);
      bool empty() const;
      size_t size() const;
      iterator begin();
      iterator end();
      const_iterator cbegin() const;
      const_iterator cend() const;

    private:
      std::list< contact_t > data_;
  };
}

#endif
