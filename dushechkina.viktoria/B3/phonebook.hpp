#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <list>
#include <string>

namespace dushechkina
{
  class Phonebook
  {
  public:
    struct Record
    {
      std::string phoneNumber;
      std::string name;
    };

    using iterator = std::list< Record >::iterator;

    iterator begin();
    iterator end();
    void insertBeforeCurrentRecord(iterator& current, const Record& newRecord);
    void insertAfterCurrentRecord(iterator& current, const Record& newRecord);
    void insertAtTheEnd(const Record& newRecord);
    void removeCurrentRecord(iterator& current);
    bool isEmpty() const;
  private:
    std::list< Record > records_;
  };
}

#endif
