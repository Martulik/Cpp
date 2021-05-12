#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <list>

namespace pochernin
{
  class PhoneBook
  {
  public:
    struct entry_t
    {
      std::string number;
      std::string name;
    };

    void pushBack(const entry_t& entry);

  private:
    std::list< entry_t > data_;
  };
}

#endif