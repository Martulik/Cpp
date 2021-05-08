#include "interface.hpp"
#include <stdexcept>
#include <functional>
#include <algorithm>

namespace poz = pozdnyakov;

poz::Interface::Interface(std::unique_ptr< poz::Phonebook > book, std::ostream& out):
  book_(std::move(book)),
  out_(out)
{
  bookmarks_.insert({"current", -1});
}

void poz::Interface::doCommand(poz::Interface::argsType args)
{
  auto commandPairIt = commands_.find(args[0]);
  bool isValidBm;
  if (commandPairIt == commands_.end())
  {
    out_ << "<INVALID COMMAND>" << '\n';
    return;
  }
  if (args[0] != "add")
  {
    if (args[0] != "insert")
    {
      isValidBm = checkBookmark(bookmarks_, args[1], out_);
    }
    else
    {
      isValidBm = checkBookmark(bookmarks_, args[2], out_);
    }
    if (!isValidBm)
    {
      return;
    }
  }
  auto commandPtr = std::get<1>(*commandPairIt);
  args.erase(args.begin());
  (this->*commandPtr)(args);
}

void poz::Interface::doAdd(poz::Interface::argsType args)
{
  // check
  std::pair< int, std::string > arg{std::stoi(args[0]), args[1]};
  book_->pushBack(arg);
  if (book_->size() == 1)
  {
    int number = std::get<0>(*book_->begin());
    auto move = [number](poz::Interface::bmsType::value_type& pair)
    {
      std::get<1>(pair) = number;
    };
    std::for_each(bookmarks_.begin(), bookmarks_.end(), move);
  }
}

void poz::Interface::doStore(poz::Interface::argsType args)
{
  bookmarks_.insert({args[0], std::stoi(args[1])});
}

void poz::Interface::doInsert(poz::Interface::argsType args)
{
  std::pair< int, std::string > pair{std::stoi(args[2]), args[3]};
  poz::Phonebook::iterator it = poz::getEntry(book_, bookmarks_, args[1]);
  if (args[0] == std::string("before"))
  {
    book_->insertBefore(it, pair);
  }
  else if (args[0] == std::string("after"))
  {
    book_->insertAfter(it, pair);
  }
  else
  {
    out_ << "<INVALID COMMAND>" << '\n';
  }
}

void poz::Interface::doDelete(poz::Interface::argsType args)
{
  std::map< std::string, int >::iterator bookmarkIt = bookmarks_.find(args[0]);
  int number = std::get<1>(*bookmarkIt);
  auto condPtr = std::bind(&poz::compareEntry, std::placeholders::_1, number);
  poz::Phonebook::iterator it = std::find_if(book_->begin(), book_->end(), condPtr);
  if (it == book_->end())
  {
    bookmarks_.erase(bookmarkIt);
  }
  else
  {
    std::get<1>(*bookmarkIt) = std::get<0>(*std::next(it));
  }
  book_->erase(it);
}

void poz::Interface::doShow(poz::Interface::argsType args)
{
  if (book_->begin() == book_->end())
  {
    out_ << "<EMPTY>" << '\n';
    return;
  }
  poz::Phonebook::iterator it = poz::getEntry(book_, bookmarks_, args[0]);
  this->out_ << std::get<1>(*it) << ' ' << std::get<0>(*it) << '\n';
}

void poz::Interface::doMove(poz::Interface::argsType args)
{
  poz::Phonebook::iterator it = poz::getEntry(book_, bookmarks_, args[0]);
  book_->move(it, std::stoi(args[1]));
}

poz::Phonebook::iterator poz::getEntry(poz::Interface::bookPtr& book, poz::Interface::bmsType bms, std::string bmName)
{
  int number = std::get<1>(*bms.find(bmName));
  auto condPtr = std::bind(&poz::compareEntry, std::placeholders::_1, number);
  poz::Phonebook::iterator it = std::find_if(book->begin(), book->end(), condPtr);
  return it;
}

bool poz::compareEntry(std::pair< int, std::string > entry, int number)
{
  return std::get<0>(entry) == number;
}

bool poz::checkBookmark(poz::Interface::bmsType bms, std::string name, std::ostream& out)
{
  poz::Interface::bmsType::iterator it = bms.find(name);
  if (it == bms.end())
  {
    out << "<INVALID BOOKMARK>" << '\n';
    return false;
  }
  return true;
}
