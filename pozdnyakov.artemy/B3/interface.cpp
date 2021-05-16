#include "interface.hpp"
#include <stdexcept>
#include <sstream>
#include <functional>
#include <iterator>
#include <algorithm>
#include "field-handlers.hpp"
#include "tools.hpp"

namespace poz = pozdnyakov;

poz::Interface::Interface(std::unique_ptr< poz::Phonebook > book, std::istream& in, std::ostream& out):
  book_(std::move(book)),
  in_(in),
  out_(out),
  bookmarks_(poz::BmContainer(book_))
{}

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
      isValidBm = bookmarks_.checkBookmark(args[1], out_);
    }
    else
    {
      isValidBm = bookmarks_.checkBookmark(args[2], out_);
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
  while(!in_.eof() && std::getline(in_, buf) && !buf.empty())
  {
    std::vector< std::string > args;
    nameBegin = buf.find('\"');
    if (nameBegin != std::string::npos && buf[nameBegin - 1] != ' ')
    {
      out_ << "<INVALID COMMAND>" << '\n';
      continue;
    }
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
    bookmarks_.reset();
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
  std::string number = bookmarks_.at(args[1]);
  poz::Phonebook::iterator it = poz::getEntry(book_, number);
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
  if (book_->size() == 0)
  {
    out_ << "<BOOK IS EMPTY>" << '\n';
  }
  else
  {
    bookmarks_.deleteEntry(args[0]);
  }
}

void poz::Interface::doShow(poz::Interface::argsType args)
{
  if (book_->size() == 0)
  {
    out_ << "<EMPTY>" << '\n';
    return;
  }
  bookmarks_.show(args[0], out_);
}

void poz::Interface::doMove(poz::Interface::argsType args)
{
  bookmarks_.move(args[0], args[1]);
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
