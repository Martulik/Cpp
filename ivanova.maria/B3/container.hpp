#ifndef B3_CONTAINER_FACTORIAL_HPP
#define B3_CONTAINER_FACTORIAL_HPP

#include <iterator>

namespace ivanova
{
  using bidiriter = std::bidirectional_iterator_tag;
  class Container
  {
  public:
    using value_type = unsigned int;
    Container() = default;
    class Iterator: public std::iterator< bidiriter, size_t >
    {
    public:
      Iterator();
      Iterator &operator ++();
      Iterator operator ++(int);
      Iterator &operator --();
      Iterator operator --(int);
      const value_type &operator *() const;
      const value_type *operator ->() const;
      bool operator ==(const Iterator &iter) const;
      bool operator !=(const Iterator &iter) const;
    private:
      friend class Container;
      size_t index_;
      value_type value_;
      Iterator(size_t index, value_type value);
    };
    Iterator begin() const;
    Iterator end() const;
  };

  constexpr Container::value_type factorial(size_t number);
}
#endif
