#ifndef FACTORIAL_LIST_H
#define FACTORIAL_LIST_H

#include <iterator>

namespace lysenko
{
  class FactorialList
  {
  public:
    class Iterator: public std::iterator<std::bidirectional_iterator_tag, unsigned int>
    {
    public:
      const unsigned int* operator->();
      const unsigned int &operator*();
      Iterator &operator++();
      Iterator &operator--();
      Iterator operator++(int);
      Iterator operator--(int);
      bool operator ==(const Iterator& other) const;
      bool operator !=(const Iterator& other) const;

    private:
      unsigned int content_;
      unsigned int index_;

      Iterator();
      Iterator(unsigned int content, unsigned int index);

      friend class FactorialList;
    };

    using reverseIterator = std::reverse_iterator< Iterator >;

    FactorialList() = default;

    Iterator begin() const noexcept;
    Iterator end() const noexcept;

    reverseIterator rbegin() const noexcept;
    reverseIterator rend() const noexcept;

    static const size_t MINIMUM_INDEX = 1;
    static const size_t MAXIMUM_INDEX = 11;
  };
}

#endif
