#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace ezerinia {
  class Container {
  public:
    using value_type = unsigned int;
    class Iterator;
    Container() = default;
    Iterator begin();
    Iterator end();
  };

  class Container::Iterator: public std::iterator< std::bidirectional_iterator_tag, value_type > {
  public:
    Iterator();
    Iterator &operator++();
    Iterator &operator--();
    Iterator operator++(int);
    Iterator operator--(int);
    bool operator==(const Iterator &src) const;
    bool operator!=(const Iterator &src) const;
    value_type &operator*();
    value_type *operator->();
  private:
    size_t index_;
    value_type value_;
  };
}
#endif
