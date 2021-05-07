#ifndef B3_CONTAINER_FACTORIAL_HPP
#define B3_CONTAINER_FACTORIAL_HPP

#include <iterator>

namespace ivanova
{
  using bidiriter = std::bidirectional_iterator_tag;
  class Container
  {
  public:
    Container() = default;
    class Iterator: public std::iterator< bidiriter, size_t >
    {
    public:
      Iterator(size_t index_);
      Iterator &operator ++();
      Iterator operator ++(int);
      Iterator &operator --();
      Iterator operator --(int);
      const size_t &operator *() const;
      bool operator ==(const Iterator &iter) const;
      bool operator !=(const Iterator &iter) const;
    private:
      size_t index_;
      size_t value_;
      constexpr int factorial(size_t number) ;
    };
    Iterator begin() const;
    Iterator end() const;
  };
}
#endif
