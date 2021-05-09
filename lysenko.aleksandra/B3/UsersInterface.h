#ifndef USERS_INTERFACE_HPP
#define USERS_INTERFFACE_HPP

#include "TelephoneBook.h"

#include <string>
#include <map>

namespace lysenko
{
  typedef std::list< lysenko::Book::Note >::iterator iterator;

  class UsersInterface
  {
  public:
    struct bookMark
    {
      std::string markName;
      iterator contact;
    };


    typedef std::list< UsersInterface::bookMark >::iterator iteratorMark;

    UsersInterface();

    void addNumber(std::string name, std::string number);
    void createNewBookMarkHere(std::string oldMarkName, std::string newMarkName);
    void insertNoteNextToBookMark(bool before, std::string markName, std::string name, std::string number);
    void deleteThisNote(std::string markName);
    void showThisNote(std::string markName);
    void removeThisBookMark(std::string markName, bool first, bool last, bool forward, const char* steps);

  private:
    std::list< bookMark > bookMarks_;
    Book telephoneBook_;

    iteratorMark findThisMark(std::string thisMark);
  };
}
#endif