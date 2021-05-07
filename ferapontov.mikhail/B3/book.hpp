#ifndef BOOK_HPP
#define BOOK_HPP

#include <utility>
#include <string>
#include <list>

namespace ferapontov
{
  using data = std::pair< std::string, int>;
  using iter = std::list< data >::iterator;
  class PhoneBook
  {
    public:
      data& showCurrent(iter it) const;
      iter next() const;
      iter previous() const;
      void insertPrev(const data& phoneNote);
      void insertNext(const data& phoneNote);
      void replace(const data& phoneNote);
      void deleteNote(data& PhoneNote);
      void pushBack(data& PhoneNote);
      iter move(iter it, int steps) const;
    private:
      std::list< data > notes;
  };
}

#endif
