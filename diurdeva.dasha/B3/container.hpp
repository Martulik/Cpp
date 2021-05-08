#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace diurdeva{
  class Container
  {
  public:
    Container() = default;
    class IteratorFact: public std::iterator< std::bidirectional_iterator_tag, size_t >
    {
    public:
      IteratorFact() = default;

      size_t* operator->();
      const size_t& operator*() const;
      IteratorFact& operator++();
      IteratorFact operator++(int);
      IteratorFact& operator--();
      IteratorFact operator--(int);

      bool operator==(const IteratorFact& rhs) const;
      bool operator!=(const IteratorFact& rhs) const;
    private:
      friend class Container;
      size_t pos_;
      size_t value_;
      IteratorFact(size_t value, size_t pos);
    };

    const IteratorFact begin();
    const IteratorFact end();
  };
}

#endif
