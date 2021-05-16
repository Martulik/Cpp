#include "BookWrap.hpp"
#include "tools.hpp"

#include <iostream>
#include <sstream>

namespace lab = shkurov;

lab::BookWrap::BookWrap(lab::PhoneBook& book, std::ostream& out):
  book_(std::make_unique< PhoneBook >(book)),
  out_(out)
{
  bookmarks_.insert({"current", book_->begin()});
}

void lab::BookWrap::doAction(const std::string& tag, std::istringstream& istr)
{
  if (tag == "add")
  {
    std::string number;
    std::string name;

    istr >> std::ws >> number;
    getline(istr >> std::ws, name);

    add(number, name);
  }
  else if (tag == "store")
  {
    std::string oldMark;
    std::string newMark;

    istr >> oldMark >> newMark;
    if (!isCorrectBookmarkName(newMark))
    {
      throw std::runtime_error("invalid bookmark name");
    }

    iterator it = bookmarks_.find(oldMark);
    if (it == bookmarks_.end())
    {
      throw std::runtime_error("<INVALID BOOKMARK>\n");
    }

    bookmarks_.insert({newMark, it->second});
  }
  else if (tag == "insert")
  {
    std::string insertion;
    std::string mark;
    std::string name;
    std::string number;

    istr >> insertion >> mark >> number;
    getline(istr >> std::ws, name);

    iterator it = bookmarks_.find(mark);
    PhoneBook::const_iterator_t bookIter = it->second;
    if (it == bookmarks_.end())
    {
      throw std::runtime_error("<INVALID BOOKMARK>\n");
    }
    if (insertion == "after")
    {
      if (bookIter == std::prev(book_->end()) || bookIter == book_->end())
      {
        add(number, name);
      }
      else
      {
        book_->insertForward(bookIter, {nameCorrection(name), number});
      }
    }
    else if (insertion == "before")
    {
      if (bookIter == std::prev(book_->end()) || bookIter == book_->end())
      {
        add(number, name);
      }
      else
      {
        book_->insertBackward(bookIter, {nameCorrection(name), number});
      }
    }
    else
    {
      throw std::runtime_error("<INVALID COMMAND>\n");
    }
  }
  else if (tag == "delete")
  {
    std::string mark;

    istr >> mark;

    iterator it = bookmarks_.find(mark);
    if (it == bookmarks_.end())
    {
      throw std::runtime_error("<INVALID BOOKMARK>\n");
    }

    PhoneBook::const_iterator_t bookIter = it->second;
    PhoneBook::const_iterator_t nextIter = std::next(bookIter);

    book_->deleteNode(bookIter);
    bookmarks_.erase(mark);

    if (nextIter != book_->end())
    {
      bookmarks_.insert({mark, nextIter});
    }
    else
    {
      bookmarks_.insert({mark, book_->begin()});
    }
  }
  else if (tag == "show")
  {
    std::string mark;

    istr >> mark;

    iterator it = bookmarks_.find(mark);
    if (it == bookmarks_.end())
    {
      throw std::runtime_error("<INVALID BOOKMARK>\n");
    }

    if (!(book_->size() == 0))
    {
      printNode(out_, book_->pullCurrent(it->second));
    }
    else
    {
      throw std::runtime_error("<EMPTY>\n");
    }
  }
  else if (tag == "move")
  {
    std::string mark;
    std::string steps;

    istr >> mark;
    istr >> steps;

    iterator it = bookmarks_.find(mark);
    if (it == bookmarks_.end())
    {
      throw std::runtime_error("<INVALID BOOKMARK>\n");
    }

    PhoneBook::const_iterator_t recordIt = it->second;

    if (isNumber(steps))
    {
       book_->move(recordIt, std::stoi(steps));
    }
    else
    {
      if (steps == "last" || steps == "first")
      {
        book_->move(recordIt, steps);
      }
      else
      {
        throw std::runtime_error("<INVALID STEP>\n");
      }
    }

    bookmarks_.erase(mark);
    bookmarks_.insert({mark, recordIt});
  }
  else if (tag == "size")
  {
    out_ << book_->size() << '\n';
  }
  else
  {
    throw std::runtime_error("<INVALID COMMAND>\n");
  }
}

void lab::BookWrap::add(const std::string& number, const std::string& name)
{
  book_->pushBack(std::pair< std::string, std::string >(nameCorrection(name), number));

  if (book_->size() == 1)
  {
    bookmarks_["current"] = book_->begin();
  }
}
