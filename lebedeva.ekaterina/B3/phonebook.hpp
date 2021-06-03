#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <list>
#include "record.hpp"

namespace lebedeva
{
  class PhoneBook
  {
  public:
    using constIter = std::list< record_t >::const_iterator;
    using Iterator = std::list< record_t >::iterator;
    constIter begin() const;
    constIter end() const;
    bool empty() const;
    size_t size() const;

    void insertBefore(constIter iter, const record_t& rec);
    void insertAfter(constIter iter, const record_t& rec);
    void replaceRec(Iterator iter, const record_t& rec);
    void deleteRec(constIter iter);
    void pushBack(const record_t& rec);
  private:
    std::list< record_t > data_;
  };
}
#endif
