#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <vector>
#include <iosfwd>

namespace shkurov
{
  class PhoneBook
  {
    public:
      using number_t = unsigned long long;
      using node_t = std::pair< std::string, number_t >;
      using iterator_t = std::vector< node_t >::iterator;
      using const_iterator_t = std::vector< node_t >::const_iterator;

      iterator_t begin();
      iterator_t end();

      void insertForward(const_iterator_t& it, const node_t& node);
      void insertBackward(const_iterator_t& it, const node_t& node);
      node_t pullCurrent(const const_iterator_t& it) const;
      void replaceCurrent(const iterator_t& it, const node_t& node);
      void pushBack(const node_t& node);
      void move(const_iterator_t& it, int steps);

      size_t size() const;

    private:
      bool iteratorInRange(const const_iterator_t& it) const;

      std::vector< node_t > container_;
  };
}

#endif