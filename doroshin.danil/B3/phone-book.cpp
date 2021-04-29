#include "phone-book.hpp"
#include <iostream>
#include <stdexcept>

namespace dan = doroshin;

dan::PhoneBook::PhoneBook():
  entries_(),
  bookmarks_()
{
  bookmarks_.emplace("current", entries_.end());
}

void dan::PhoneBook::add(Entry entry)
{
  entries_.emplace_back(std::move(entry));
  if(bookmarks_.at("current") == entries_.end()) {
    bookmarks_.at("current") = --entries_.end();
  }
}

void dan::PhoneBook::store(const Name& from, const Name& to)
{
  try {
    bookmarks_.insert({to, bookmarks_.at(from)});
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::insert_before(const Name& mark, Entry entry)
{
  try {
    entries_.emplace(bookmarks_.at(mark), std::move(entry));
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::insert_after(const Name& mark, Entry entry)
{
  try {
    Iter i = bookmarks_.at(mark);
    if(i != entries_.end()) {
      i++;
    }
    entries_.emplace(i, std::move(entry));
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::delete_contents(const Name& mark)
{
  try {
    Iter del = bookmarks_.at(mark);
    for(auto& bookmark: bookmarks_) {
      if(bookmark.second == del) {
        bookmark.second++;
        if(bookmark.second == entries_.end()) {
          bookmark.second = entries_.begin();
        }
      }
    }
    entries_.erase(del);
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

dan::PhoneBook::Entry dan::PhoneBook::show(const Name& mark) const
{
  Iter res;
  try {
    res = bookmarks_.at(mark);
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
  if(res == entries_.end()) {
    throw std::out_of_range("<EMPTY>");
  }
  return *res;
}

void dan::PhoneBook::move_front(const Name& mark)
{
  try {
    bookmarks_.at(mark) = entries_.begin();
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::move_back(const Name& mark)
{
  try {
    if(!entries_.empty()) {
      bookmarks_.at(mark) = --entries_.end();
    }
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

void dan::PhoneBook::move(const Name& mark, int steps)
{
  try {
    Iter& i = bookmarks_.at(mark);
    if(steps > 0) {
      while(steps) {
        if(++i == entries_.end()) {
          i = entries_.begin();
        }
        steps--;
      }
    }
    else {
      while(steps) {
        if(i == entries_.begin()) {
          i = entries_.end();
        }
        i--;
        steps++;
      }
    }
  }
  catch(const std::out_of_range&) {
    throw InvalidBookmarkException();
  }
}

const char* dan::InvalidBookmarkException::what() const noexcept
{
  return "<INVALID BOOKMARK>";
}
