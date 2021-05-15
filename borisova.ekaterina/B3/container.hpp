#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace borisova
{
  class Container
  {
  public:
    using unInt = unsigned int;
    class Iterator;
    Container() = default;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, unInt >
    {
    public:
      Iterator();
      Iterator& operator++();
      Iterator operator++(int);
      Iterator& operator--();
      Iterator operator--(int);
      bool operator==(const Iterator& src) const;
      bool operator!=(const Iterator& src) const;
      const unInt& operator*();
      const unInt* operator->();

    private:
      friend class Container;
      Iterator(unInt value, unInt index);
      unInt index_;
      unInt value_;
    };
  };
}
#endif
