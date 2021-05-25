#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <iterator>

namespace lebedeva
{
  class Container
  {
  public:
    Container() = default;
    using valueType = unsigned int;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, valueType >
    {
    public:
      const valueType* operator->();
      const valueType& operator*();
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);

      bool operator==(const Iterator& rhs) const;
      bool operator!=(const Iterator& rhs) const;
    private:
      friend class Container;
      valueType index_;
      valueType value_;

      Iterator();
      Iterator(valueType i, valueType value);
    };
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
  };
}
#endif
