#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include <string>

namespace pozdnyakov
{
  class Phonebook
  {
  public:
    using value_type = std::pair< std::string, std::string >;
    using const_iterator = std::list< value_type >::const_iterator;
    Phonebook() = default;
    const_iterator cbegin();
    const_iterator cend();
    void pushBack(value_type& val);
    const_iterator insert(const_iterator position, const value_type& val);
    const_iterator erase(const_iterator it);
    size_t size();
  private:
    using iterator = std::list< value_type >::iterator;
    std::list< value_type > book_;
    iterator begin();
    iterator end();
  };
}

#endif
