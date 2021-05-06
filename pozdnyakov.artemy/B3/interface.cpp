#include "interface.hpp"

namespace poz = pozdnyakov;

poz::Interface(std::unique_ptr< Phonebook > book, std::ostream& out):
  book_(std::move(book)),
  out_(out)
{
  bookmarks_.insert({"current", *(book_->begin())});
}

void poz::Interface::doCommand(poz::Interface::argsType args)
{
  void(poz::Interface::*command)(poz::argsType) = command_[args[0]];
  args.erase(args.begin());
  command(args);
}

void poz::Interface::doAdd(poz::Interface::argsType args)
{
  // check
  book_->pushBack({args[0], std::stoi(args[1])});
}

void poz::Interface::doStore(poz::Interface::asrgsType args)
{
  bookmarks_.insert({args[0], args[1]});
}

void poz::Inteface::doInsert(poz::Interface::argsType args)
{
  std::pair< int, std::string > pair{args[2], std::stoi(args[3])};
  typedef poz::Phonebook::iterator it = bookmarks_.find(args[1]);
  if (args[0] == std::string("before"))
  {
    book_->insertBefore(it, pair)
  }
}

void poz::Interface::doDelete(poz::Interface::argsType args)
{
  typedef poz::Phonebook::iterator it = bookmarks_.find(args[1]);
  book_->erase(it);
}

void poz::Interface::doShow(poz::Interface::argsType args)
{
  typedef poz::Phonebook::iterator it = bookmarks_.find(args[1]);
  Interface::out << std::get<0>(*it) << ' ' << std::get<0>(*it) << '\n';
}

void poz::Interface::doMove(poz::Interface::argsType args)
{
  typedef poz::Phonebook::iterator it = bookmarks_.find(args[0]);
  book_->move(*it, std::stoi(args[1]));
}
