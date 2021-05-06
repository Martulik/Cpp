#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iosfwd>
#include <string>
#include <list>

namespace ivanova
{
  class PhoneBook
  {
  public:
    struct Record
    {
      std::pair< std::string, std::string > value;
    };
//    std::ostream &operator <<(std::ostream &out, const Phonebook); //TODO: оператор вывода сделать

//    using Record = std::pair< std::string, std::string >;
    using iter = std::list< Record >::iterator;

    iter begin();
    iter end();
    void add(const Record &record);
    void insert(const iter &userIt, const Record &record);
    void erase(const iter &iter);
    iter moveOnStep(iter &iter, int step);
    size_t size() const;
    bool isEmpty() const;

  private:
    using ListOfRecord = std::list< Record >;
    ListOfRecord list_;
  };

  std::ostream &operator <<(std::ostream &out, const PhoneBook::iter &iter);
}
#endif
