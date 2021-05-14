#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>
#include "note.hpp"

namespace murzakanov
{
  class PhoneBook
  {
  public:
    using iterator = std::list< murzakanov::note_t >::iterator;
    using const_iterator = std::list< murzakanov::note_t >::const_iterator;

    void insertAfter(const_iterator it, const murzakanov::note_t& note);
    void insertBefore(const_iterator it, const murzakanov::note_t& note);
    void deleteNote(const_iterator it);
    void push_back(const murzakanov::note_t& note);
    size_t size() const;
    bool isEmpty() const;

    const_iterator begin();
    const_iterator end();
  private:
    std::list< murzakanov::note_t > book_;
  };
}

#endif
