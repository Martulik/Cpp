#include "PhoneBook.hpp"

#include <utility>
#include <iostream>
#include <stdexcept>

namespace lab = shkurov;

lab::PhoneBook::const_iterator_t lab::PhoneBook::begin()
{
  return container_.cbegin();
}

lab::PhoneBook::const_iterator_t lab::PhoneBook::end()
{
  return container_.cend();
}

void lab::PhoneBook::insertForward(lab::PhoneBook::const_iterator_t& it, const lab::PhoneBook::node_t& node)
{
  if (it == std::prev(container_.end()) || it == container_.end())
  {
    container_.push_back(node);
  }
  else
  {
    container_.insert(++it, node);
  }
}

void lab::PhoneBook::insertBackward(lab::PhoneBook::const_iterator_t& it, const lab::PhoneBook::node_t& node)
{
  if (it == container_.begin())
  {
    container_.push_front(node);
  }
  else
  {
    container_.insert(it, node);
  }
}

lab::PhoneBook::node_t lab::PhoneBook::pullCurrent(const lab::PhoneBook::const_iterator_t& it) const
{
  return *it;
}

void lab::PhoneBook::pushBack(const node_t& node)
{
  container_.push_back(node);
}

void lab::PhoneBook::pushFront(const node_t& node)
{
  container_.push_front(node);
}

void lab::PhoneBook::move(lab::PhoneBook::const_iterator_t& it, int steps)
{
  std::advance(it, steps);
}

void lab::PhoneBook::move(lab::PhoneBook::const_iterator_t& it, const std::string& pos)
{
  if (pos == "first")
  {
    it = container_.cbegin();
  }
  else if (pos == "last")
  {
    if (size() == 0)
    {
      it = container_.cend();
    }
    else
    {
      it = --container_.cend();
    }
  }
}

size_t lab::PhoneBook::size() const
{
  return container_.size();
}

lab::PhoneBook::const_iterator_t lab::PhoneBook::deleteNode(const lab::PhoneBook::const_iterator_t& it)
{
  return container_.erase(it);
}
