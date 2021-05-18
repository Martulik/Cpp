#ifndef FACTORIAL_LIST_H
#define FACTORIAL_LIST_H

#include <iterator>

namespace lysenko
{
  class FactorialList
  {
  public:
    class Iterator : public std::iterator< std::bidirectional_iterator_tag, unsigned int >
    {
    public:
      Iterator();

      const unsigned int* operator->();
      const unsigned int& operator*();
      Iterator& operator++();
      Iterator& operator--();
      Iterator operator++(int);
      Iterator operator--(int);
      bool operator ==(const Iterator& other) const;
      bool operator !=(const Iterator& other) const;

    private:
      unsigned int content_;
      unsigned int index_;

      Iterator(unsigned int content, unsigned int index);

      friend class FactorialList;
    };

    using reverseIterator = std::reverse_iterator< Iterator >;

    Iterator begin() const noexcept;
    Iterator end() const noexcept;

    reverseIterator rbegin() const noexcept;
    reverseIterator rend() const noexcept;

    static constexpr unsigned int MINIMUM_INDEX = 1;
    static constexpr unsigned int MAXIMUM_INDEX = 11;

    FactorialList() = default;
  };
}

#endif
