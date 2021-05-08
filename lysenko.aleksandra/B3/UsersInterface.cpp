#include "UsersInterface.hpp"

#include <iostream>
#include <list>

#include "exceptions.h"

lysenko::UsersInterface::UsersInterface() :
  telephoneBook_(),
  bookMarks_()
{
  bookMarks_.push_front({ "current", telephoneBook_.getBegin() });
};

void lysenko::UsersInterface::addNumber(std::string name, std::string number)
{
  telephoneBook_.pushBack({ name, number });
}

lysenko::UsersInterface::iteratorMark lysenko::UsersInterface::findThisMark(std::string thisMark)
{
  bool markIsFound = 0;
  lysenko::UsersInterface::iteratorMark checkMark = bookMarks_.begin();
  while ((markIsFound == 0) && (checkMark != bookMarks_.end()))
  {
    if (checkMark->markName == thisMark)
    {
      markIsFound == 1;
    }
    else
    {
      checkMark = ++checkMark;
    }
  }
  return checkMark;
}

void lysenko::UsersInterface::createNewBookMarkHere(std::string oldMarkName, std::string newMarkName)
{
  iteratorMark newBookMark = findThisMark(oldMarkName);
  bookMarks_.push_front({ newMarkName, newBookMark->contact });
}
///при вызове из command поставить try  
///iteratorMark newBookMark = findThisMark(oldMarkName);
//if (newBookMark == telephoneBook_.getEnd())
//{
//  InvalidBookmark;
//} 
// и этот catch
  //catch (InvalidBookmark& err)
  //{
  //  std::cout << err.what();
  //  return;
  //}

void lysenko::UsersInterface::insertNoteNextToBookMark(bool before, std::string markName, std::string name, std::string number)
{
  iteratorMark curr = findThisMark(markName);
  telephoneBook_.insert(curr->contact, {name, number}, before);
  ///при вызове из command поставить try  
  ///iteratorMark newBookMark = findThisMark(markName);
  //if (newBookMark == telephoneBook_.getEnd())
  //{
  //  InvalidBookmark;
  //} 
  // и этот catch
    //catch (InvalidBookmark& err)
    //{
    //  std::cout << err.what();
    //  return;
    //};
}

void lysenko::UsersInterface::deleteThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  telephoneBook_.deleteNote(curr->contact);
  ///при вызове из command поставить try  
  ///iteratorMark newBookMark = findThisMark(markName);
  //if (newBookMark == telephoneBook_.getEnd())
  //{
  //  InvalidBookmark;
  //} 
  // и этот catch
    //catch (InvalidBookmark& err)
    //{
    //  std::cout << err.what();
    //  return;
    //};
}

void lysenko::UsersInterface::showThisNote(std::string markName)
{
  iteratorMark curr = findThisMark(markName);
  telephoneBook_.showCurrNote(curr->contact);
  ///при вызове из command написать сначала  
//
//if (telephoneBook_.isEmpty())
//{
//  std::cout <<"<EMPTY>";
//} 
// else
  //{
  //  вызов функции
  //}
}

void lysenko::UsersInterface::removeThisBookMark(std::string markName,bool first, bool last, bool forward, const char* steps )
{
  iteratorMark curr = findThisMark(markName);
  iterator note;
  if (first)
  {
    note = telephoneBook_.getBegin();
  }
  else if (last)
  {
    note = telephoneBook_.getEnd();
  }
  else
  {
    int intSteps = atoi(steps);
    if (forward)
    {
      note = telephoneBook_.goTo(curr->contact, 1, intSteps);
    }
    else
    {
      intSteps = abs(intSteps);
      note = telephoneBook_.goTo(curr->contact, 0, intSteps);
    }
  }
  curr->contact = note;
  /*math.h
    <string>*/
  ///при вызове из command поставить try  
 ///iteratorMark newBookMark = findThisMark(markName);
 //if ((std::atoi(steps)||(steps=="first")||(steps=="last"))
 //{
 //  if (std::atoi(steps))
//  {
//    if (steps > 0)
//    {
//      removeThisBookMark(markName,0,0,1,  steps)
//    }
//    else
//    {
//      removeThisBookMark(markName,0,0, 0, steps)
//    }
//  }
//  else if (steps == "first")
//  {
//    removeThisBookMark(markName, 1, 0, 0, steps)
//  }
//  else
//  {
//  removeThisBookMark(markName, 0, 1, 0, steps)
//  }
//
// }
//else
//{
//InvalidStep;
//}

 //} 
 // и этот catch
   //catch (InvalidStep& err)
   //{
   //  std::cout << err.what();
   //  return;
   //};

 /* а еще */
  ///при вызове из command поставить try  
  ///iteratorMark newBookMark = findThisMark(markName);
  //if (newBookMark == telephoneBook_.getEnd())
  //{
  //  InvalidBookmark;
  //} 
  // и этот catch
    //catch (InvalidBookmark& err)
    //{
    //  std::cout << err.what();
    //  return;
    //};
}
