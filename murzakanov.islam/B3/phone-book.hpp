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

    void insertAfter(iterator it, const murzakanov::note_t& note);
    void insertBefore(iterator it, const murzakanov::note_t& note);
    void deleteNote(iterator it);
    void push_back(const murzakanov::note_t& note);
    void replace(iterator it, const murzakanov::note_t& note);
    void show(std::ostream& out, iterator it) const;
    size_t size() const;
    bool isEmpty() const;

    iterator begin();
    iterator end();
  private:
    std::list< murzakanov::note_t > book_;
  };
}

#endif
