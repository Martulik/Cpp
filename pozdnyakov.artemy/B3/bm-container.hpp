#ifndef BOOKMARK_HPP
#define BOOKMARK_HPP

#include <memory>
#include <map>
#include <iostream>
#include "phonebook.hpp"

namespace pozdnyakov
{
  class BmContainer
  {
  public:
    BmContainer(std::unique_ptr< Phonebook >& book);
    void store(std::string bmName, std::string number);
    void deleteEntry(std::string bmName);
    void show(std::string bmName, std::ostream& out);
    void move(std::string bmName, std::string step);
    std::string at(std::string bmName);
    void insert(std::pair< std::string, std::string > entry);
    bool checkBookmark(std::string bmName, std::ostream& out = std::cout);
  private:
    friend class Interface;
    void reset();
    std::unique_ptr< Phonebook >& book_ ;
    std::map< std::string, std::string > bookmarks_;
  };
}

#endif
