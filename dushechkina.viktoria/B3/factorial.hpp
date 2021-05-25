#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP
#include <iterator>

namespace dushechkina
{
  class Container
  {
  public:
    class Iterator: public std::iterator<std::bidirectional_iterator_tag, unsigned int>
    {
    public:
      Iterator();
      const unsigned int* operator->();
      const unsigned int& operator*();
      bool operator==(const Iterator& rhs) const;
      bool operator!=(const Iterator& rhs) const;
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
    private:
      Iterator(unsigned int index);
      friend class Container;
      unsigned int index_;
      unsigned int factorial_;
    };
    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}

#endif
