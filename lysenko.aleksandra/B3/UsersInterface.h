#ifndef USERS_INTERFACE_HPP
#define USERS_INTERFACE_HPP

#include "TelephoneBook.h"

#include <string>
#include <map>

namespace lysenko
{
  class UsersInterface
  {
  public:
    UsersInterface();

    typedef std::list< Book::Note >::iterator iterator;

    struct bookMark
    {
      std::string markName;
      iterator contact;
    };

    typedef std::list< UsersInterface::bookMark >::iterator iteratorMark;

    iteratorMark getEndOfBookMarks();
    bool telephoneBookIsEmpty();

    void addNumber(std::string name, std::string number);
    void createNewBookMarkHere(std::string oldMarkName, std::string newMarkName);
    void insertNoteNextToBookMark(bool before, std::string markName, std::string name, std::string number);
    void deleteThisNote(std::string markName);
    void showThisNote(std::string markName);
    void removeThisBookMark(std::string markName, bool first, bool last, bool forward, std::string steps);

    iteratorMark findThisMark(std::string thisMark);

  private:
    std::list< bookMark > bookMarks_;
    Book telephoneBook_;
  };
}
#endif
