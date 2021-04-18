#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <list>

namespace ezerinia {
  class PhoneBook {
  public:
    using data = std::pair< std::string, std::string >;
    using iterator = std::list< data >::iterator;
    bool empty();
    iterator begin();
    iterator end();
    iterator add(iterator iter, data &src);
    iterator move(iterator iter, int step);
    iterator moveNext(iterator iter);
    iterator movePrev(iterator iter);
    iterator remove(iterator iter);
    iterator replace(iterator iter, data &src);
    void show(iterator iter);
    void pushBack(data &src);
  private:
    std::list< data > list_;
  };
}
#endif
