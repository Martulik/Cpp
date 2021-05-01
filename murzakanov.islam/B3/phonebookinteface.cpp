#include "phonebookinteface.hpp"

#include <iostream>
#include <map>
#include <string>
#include <memory>

#include "phone-book.hpp"

murzakanov::BookInterface::BookInterface(PhoneBook& book) :
  book_(std::make_unique< PhoneBook >(book))
{
  bookmarks_.insert(std::make_pair("current", book_->begin()));
}

void murzakanov::BookInterface::add(const note_t& note)
{
  book_->push_back(note);
  if (bookmarks_.size() == 1)
  {
    bookmarks_["current"] = book_->begin();
  }
}

void murzakanov::BookInterface::store(const std::string& bookmark, const std::string& newBookmark, std::ostream& out)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    bookmarks_.insert(std::make_pair(newBookmark, it->second));
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void murzakanov::BookInterface::insertBefore(const std::string& bookmark, const note_t& note, std::ostream& out)
{
  if (bookmark == "current" && book_->isEmpty())
  {
    add(note);
    return;
  }

  std::map< std::string, murzakanov::PhoneBook::iterator >::iterator it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    book_->insertBefore(it->second, note);
  }
  else
  {
    out << "<INVALID COMMAND>\n";
  }
}

void murzakanov::BookInterface::insertAfter(const std::string& bookmark, const note_t& note, std::ostream& out)
{
  if (bookmark == "current" && book_->isEmpty())
  {
    add(note);
    return;
  }

  iteratorType it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    book_->insertAfter(it->second, note);
  }
  else
  {
    out << "<INVALID COMMAND>\n";
  }
}

void murzakanov::BookInterface::deleteNote(const std::string& bookmark, std::ostream& out)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    iteratorType tempIt = it;
    iteratorType current = bookmarks_.begin();
    while (current != bookmarks_.end())
    {
      if (current->second == tempIt->second)
      {
        if (std::next(current->second) == book_->end())
        {
          current->second = book_->begin();
        }
        else
        {
          current->second = std::next(tempIt->second);
        }
      }
      current++;
    }
    book_->deleteNote(tempIt->second);
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void murzakanov::BookInterface::show(const std::string& bookmark, std::ostream& out)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    if (book_->isEmpty())
    {
      out << "<EMPTY>\n";
      return;
    }

    if (it->second != book_->end())
    {
      out << it->second->number << " " << it->second->name << "\n";
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void murzakanov::BookInterface::move(const std::string& bookmark, int steps, std::ostream& out)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    if (steps > 0)
    {
      while (steps != 0 && it->second != book_->end())
      {
        it->second = std::next(it->second);
        steps--;
      }
    }
    else
    {
      while (steps != 0 && it->second != book_->begin())
      {
        it->second = std::prev(it->second);
        steps++;
      }
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void murzakanov::BookInterface::move(const std::string& bookmark, KeyWord keyWord, std::ostream& out)
{
  iteratorType it = bookmarks_.find(bookmark);
  if (it != bookmarks_.end())
  {
    if (keyWord == KeyWord::FIRST)
    {
      it->second = book_->begin();
    }
    else if (keyWord == KeyWord::LAST)
    {
      if (book_->isEmpty())
      {
        it->second = book_->end();
      }
      else
      {
        std::prev(book_->end());
      }
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}
