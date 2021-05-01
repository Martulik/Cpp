#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <utility>
#include <list>

namespace pozdnyakov
{
  class Phonebook
  {
  public:
    using EntryType = std::pair< std::string, std::string >;
    Phonebook();
    void showCurrent(std::ostream& out);
    void nextEntry();
    void prevEntry();
    void insertEntry(EntryType entry);
    void pushBackEntry(EntryType entry);
    void move(int n);


  private:
    typedef std::list< EntryType >::iterator currEntry;
    std::list< EntryType > entries;
  };
}

#endif
