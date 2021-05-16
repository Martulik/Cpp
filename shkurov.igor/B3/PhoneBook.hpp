#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <iosfwd>

namespace shkurov
{
  class PhoneBook
  {
    public:
      using node_t = std::pair< std::string, std::string >;
      using iterator_t = std::list< node_t >::iterator;
      using const_iterator_t = std::list< node_t >::const_iterator;

      PhoneBook() = default;

      iterator_t begin();
      iterator_t end();

      void insertForward(const_iterator_t& it, const node_t& node);
      void insertBackward(const_iterator_t& it, const node_t& node);
      node_t pullCurrent(const const_iterator_t& it) const;
      void replaceCurrent(const iterator_t& it, const node_t& node);
      void pushBack(const node_t& node);
      void pushFront(const node_t& node);
      void move(const_iterator_t& it, int steps);
      void move(const_iterator_t& it, const std::string& pos);
      PhoneBook::iterator_t deleteNode(const const_iterator_t& it);

      size_t size() const;

    private:
      bool iteratorInRange(const const_iterator_t& it) const;

      std::list< node_t > container_;
  };
}

#endif
