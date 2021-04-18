#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>

namespace murzakanov
{
  class PhoneBook
  {
  public:
    struct note_t
    {
      std::string name;
      std::string number;
    };

    using iterator = std::list< note_t >::iterator;
    using const_iterator = std::list< note_t >::const_iterator;

    void insertAfter(iterator it, const note_t& note);
    void insertBefore(iterator it, const note_t& note);
    void add(const note_t& note);
  private:
    std::list< note_t > book_;
  };
}
#endif