#ifndef PHONEBOOKHPP
#define PHONEBOOKHPP

#include <list>
#include <string>

namespace diurdeva {
  class Phonebook
  {
  public:
    struct record_t
    {
      std::string name;
      std::string phone;
    };

    using list = std::list<record_t>;
    using iterator = list::iterator;

    void view(iterator) const;
    void pushBack(const record_t& rec);

    bool empty() const;

    iterator begin();
    iterator end();
    iterator next(iterator);
    iterator prev(iterator);
    iterator insert(iterator, const record_t& rec);
    iterator remove(iterator);
    iterator replace(const std::string& name, const std::string& number, iterator iterator);
    iterator move(iterator, int);
  private:
    list list_;
  };
}

#endif 
