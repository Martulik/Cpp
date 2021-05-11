#include "interface.hpp"
#include <stdexcept>
#include <sstream>
#include <functional>
#include <algorithm>
#include <iterator>
#include "field-handlers.hpp"

namespace poz = pozdnyakov;

poz::Interface::Interface(std::unique_ptr< poz::Phonebook > book, std::istream& in, std::ostream& out):
  book_(std::move(book)),
  in_(in),
  out_(out)
{
  bookmarks_.insert({"current", "-1"});
}

void poz::Interface::doCommand(poz::Interface::argsType args)
{
  const poz::CommandTable table = poz::getTable();
  if (!table.checkCommand(args))
  {
    if (!args[0].compare("move"))
    {
      out_ << "<INVALID STEP>" << '\n';
    }
    else
    {
      out_ << "<INVALID COMMAND>" << '\n';
    }
    return;
  }
  bool isValidBm;
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
  auto commandPtr = commands_.at(args[0]);
  args.erase(args.begin());
  (this->*commandPtr)(args);
}

void poz::Interface::start()
{
  std::string buf;
  std::string name;
  std::string word;
  size_t space;
  size_t nameBegin;
  size_t nameEnd;
  while(!std::cin.eof() && std::getline(in_, buf) && !buf.empty())
  {
    std::vector< std::string > args;
    nameBegin = buf.find('\"');
    nameEnd = buf.rfind('\"');
    if (nameBegin != std::string::npos)
    {
      name = buf.substr(nameBegin, nameEnd - nameBegin + 1);
      buf = buf.substr(0, nameBegin - 1);
    }
    size_t spaces = std::count(buf.begin(), buf.end(), ' ');
    for (size_t i = 0; i < spaces; i++)
    {
      space = buf.find(' ');
      word = buf.substr(0, space);
      args.push_back(word);
      buf = buf.substr(space + 1, buf.length() - space + 1);
    }
    args.push_back(buf);
    if (nameBegin != std::string::npos)
    {
      args.push_back(name);
    }
    this->doCommand(args);
  }
}

void poz::Interface::doAdd(poz::Interface::argsType args)
{
  std::pair< std::string, std::string > arg{args[0], args[1]};
  book_->pushBack(arg);
  if (book_->size() == 1)
  {
    std::string number = std::get<0>(*book_->begin());
    auto move = [number](poz::Interface::bmsType::value_type& pair)
    {
      std::get<1>(pair) = number;
    };
    std::for_each(bookmarks_.begin(), bookmarks_.end(), move);
  }
}

void poz::Interface::doStore(poz::Interface::argsType args)
{
  std::string number = bookmarks_.at(args[0]);
  bookmarks_.insert({args[1], number});
}

void poz::Interface::doInsert(poz::Interface::argsType args)
{
  std::pair< std::string, std::string > pair{args[2], args[3]};
  poz::Phonebook::iterator it = poz::getEntry(book_, bookmarks_, args[1]);
  if (it == book_->end())
  {
    args.erase(args.begin(), std::next(args.begin(), 2));
    this->doAdd(args);
    return;
  }
  if (args[0] == std::string("before"))
  {
    book_->insert(it, pair);
  }
  else if (args[0] == std::string("after"))
  {
    book_->insert(std::next(it), pair);
  }
}

void poz::Interface::doDelete(poz::Interface::argsType args)
{
  std::map< std::string, std::string >::iterator bookmarkIt = bookmarks_.find(args[0]);
  std::string number = std::get<1>(*bookmarkIt);
  auto condPtr = std::bind(&poz::compareEntry, std::placeholders::_1, number);
  poz::Phonebook::iterator it = std::find_if(book_->begin(), book_->end(), condPtr);
  if (it == book_->end())
  {
    out_ << "<BOOK IS EMPTY>" << '\n';
    return;
  }
  for(bookmarkIt = bookmarks_.begin(); bookmarkIt != bookmarks_.end(); bookmarkIt++)
  {
    std::string& numberRef = std::get<1>(*bookmarkIt);
    if (numberRef == number)
    {
      if (book_->size() == 1)
      {
        numberRef = -1;
      }
      else if(it == std::prev(book_->end()))
      {
        numberRef = std::get<0>(*book_->begin());
      }
      else
      {
        numberRef = std::get<0>(*std::next(it));
      }
    }
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
  std::string name = std::get<1>(*it);
  name.pop_back();
  name.erase(name.begin());
  std::string::iterator last = std::remove(name.begin(), name.end(), '\\');
  name = std::string(name.begin(), last);
  this->out_ << std::get<0>(*it) << ' ' << name << '\n';
}

void poz::Interface::doMove(poz::Interface::argsType args)
{
  std::string& entryRef = std::get<1>(*bookmarks_.find(args[0]));
  poz::Phonebook::iterator newIt;
  if (!args[1].compare("last"))
  {
    newIt = --book_->end();
  }
  else if (!args[1].compare("first"))
  {
    newIt = book_->begin();
  }
  else
  {
    auto condPtr = std::bind(&poz::compareEntry, std::placeholders::_1, entryRef);
    poz::Phonebook::iterator bookIt = std::find_if(book_->begin(), book_->end(), condPtr);
    int n = std::stoi(args[1]);
    bookIt = std::find_if(book_->begin(), book_->end(), condPtr);
    if (!((n >= 0 && n < std::distance(bookIt, book_->end())) || (n < 0 && n < std::distance(bookIt, book_->begin()))))
    {
      // out_ << "<INVALID STEP>" << '\n';
      return;
    }
    newIt = std::next(bookIt, n);
  }
  entryRef = std::get<0>(*newIt);
}

poz::Phonebook::iterator poz::getEntry(poz::Interface::bookPtr& book, poz::Interface::bmsType bms, std::string bmName)
{
  if (book->size() == 0)
  {
    return book->end();
  }
  std::string number = std::get<1>(*bms.find(bmName));
  auto condPtr = std::bind(&poz::compareEntry, std::placeholders::_1, number);
  poz::Phonebook::iterator it = std::find_if(book->begin(), book->end(), condPtr);
  return it;
}

bool poz::compareEntry(std::pair< std::string, std::string > entry, std::string number)
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

poz::CommandTable poz::getTable()
{
  std::vector< std::vector< std::string > > patterns
  {
    {"AddCommand", "Int", "Name"},
    {"MoveCommand", "String", "MoveParam"},
    {"AddCommand", "InsertParam", "String", "Int", "Name"},
    {"Command", "String"},
    {"Command", "String", "String"}
  };
  std::map< std::string, std::function< bool(std::string) > > fieldHandlersMap
  {
    {"AddCommand", poz::add_command_t()},
    {"Command", poz::command_t()},
    {"InsertParam", poz::insert_param_t()},
    {"MoveParam", poz::move_param_t()},
    {"Name", poz::name_t()},
    {"Int", poz::int_t()},
    {"String", poz::string_t()},
    {"MoveCommand", poz::move_command_t()}
  };
  return poz::CommandTable(patterns, fieldHandlersMap);
}
