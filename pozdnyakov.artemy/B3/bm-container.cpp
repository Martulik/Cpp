#include "bm-container.hpp"
#include <cassert>
#include <algorithm>

namespace poz = pozdnyakov;

poz::BmContainer::BmContainer(std::unique_ptr< Phonebook >& book):
  book_(book),
  bookmarks_({{"current", "-1"}})
{}

void poz::BmContainer::store(std::string bmName, std::string number)
{
  assert(poz::checkNumber(book_, number));
  bookmarks_.insert({bmName, number});
}

void poz::BmContainer::deleteEntry(std::string bmName)
{
  assert(this->checkBookmark(bmName) && book_->size() != 0);
  std::string& numberRef = bookmarks_.at(bmName);
  std::map< std::string, std::string >::iterator bmIt;
  poz::Phonebook::iterator it = poz::getEntry(book_, numberRef);
  if (book_->size() == 1)
  {
    this->reset();
  }
  else
  {
    for (bmIt = bookmarks_.begin(); bmIt != bookmarks_.end(); bmIt++)
    {
        if (it == std::prev(book_->end()))
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

void poz::BmContainer::show(std::string bmName, std::ostream& out)
{
  assert(this->checkBookmark(bmName));
  std::string number = bookmarks_.at(bmName);
  poz::Phonebook::iterator it = poz::getEntry(book_, number);
  std::string name = std::get< 1 >(*it);
  name.pop_back();
  name.erase(name.begin());
  std::string::iterator last = std::remove(name.begin(), name.end(), '\\');
  name = std::string(name.begin(), last);
  out << std::get<0>(*it) << ' ' << name << '\n';
}

void poz::BmContainer::move(std::string bmName, std::string step)
{
  assert(this->checkBookmark(bmName));
  std::string& numberRef = bookmarks_.at(bmName);
  poz::Phonebook::iterator newIt;
  if (!step.compare("last"))
  {
    newIt = --book_->end();
  }
  else if (!step.compare("first"))
  {
    newIt = book_->begin();
  }
  else
  {
    poz::Phonebook::iterator bookIt = poz::getEntry(book_, bmName);
    int n = std::stoi(step);
    if (!((n >= 0 && n < std::distance(bookIt, book_->end())) || (n < 0 && n < std::distance(bookIt, book_->begin()))))
    {
      return;
    }
    newIt = std::next(bookIt, n);
  }
  numberRef = std::get<0>(*newIt);
}

void poz::BmContainer::reset()
{
  std::string number;
  if (book_->size() == 0)
  {
    number = -1;
  }
  else
  {
    number = std::get<0>(*book_->begin());
  }
  auto move = [&number](std::pair< std::string, std::string > pair)
  {
    std::get<1>(pair) = number;
  };
  std::for_each(bookmarks_.begin(), bookmarks_.end(), move);
}

std::string poz::BmContainer::at(std::string bmName)
{
  return bookmarks_.at(bmName);
}

void poz::BmContainer::insert(std::pair< std::string, std::string > entry)
{
  bookmarks_.insert(entry);
}

bool poz::BmContainer::checkBookmark(std::string bmName, std::ostream& out)
{
  std::map< std::string, std::string >::iterator it = bookmarks_.find(bmName);
  if (it == bookmarks_.end())
  {
    out << "<INVALID BOOKMARK>" << '\n';
    return false;
  }
  return true;
}

poz::Phonebook::iterator getEntry(poz::Interface::bookPtr& book, std::string number)
{
  if (book->size() == 0)
  {
    return book->end();
  }
  auto cond = [&number](std::pair< std::string, std::string > entry)
  {
    return std::get< 0 >(entry) == number;
  };
  poz::Phonebook::iterator it = std::find_if(book->begin(), book->end(), cond);
  return it;
}

bool poz::checkNumber(poz::Interface::bookPtr& book, std::string number)
{
  auto cond = [&number](std::pair< std::string, std::string > entry)
  {
    return number == std::get< 0 >(entry);
  };
  return (std::find_if(book->begin(), book->end(), cond) != book->end());
}
