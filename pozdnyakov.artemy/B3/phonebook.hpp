#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <list>
#include <string>

namespace pozdnyakov
{
  class Phonebook
  {
  public:
    using value_type = std::pair< int, std::string >;
    using iterator = std::list< value_type >::iterator;
    using const_iterator = std::list< value_type >::const_iterator;
    Phonebook() = default;
    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();
    void pushBack(value_type& val);
    iterator insert(const_iterator position, const value_type& val);
    iterator erase(iterator it);
    void replace(iterator it, value_type& val);
    size_t size();
  private:
    std::list< value_type > book_;
  };
}

#endif
