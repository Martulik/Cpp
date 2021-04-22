#ifndef STRATEGIES_HPP
#define STRATEGIES_HPP

#include <cstddef>

namespace lysenko
{
  template<typename Container>
  struct strategyForIndex
  {
    typedef typename Container::value_type type;
    typedef size_t iterator;

    static iterator getBegin(const Container&)
    {
      return 0;
    }

    static iterator getEnd(const Container& myContainer)
    {
      return myContainer.size();
    }

    static type& getElement(Container& myContainer, iterator i)
    {
      return myContainer[i];
    }
  };

  template<typename Container>
  struct strategyForAt
  {
    typedef typename Container::value_type type;
    typedef size_t iterator;

    static iterator getBegin(Container&)
    {
      return 0;
    }

    static iterator getEnd(Container& myContainer)
    {
      return myContainer.size();
    }

    static type& getElement(Container& myContainer, iterator i)
    {
      return myContainer.at(i);
    }
  };

  template<typename Container>
  struct strategyForIterator
  {
    typedef typename Container::value_type type;
    typedef typename Container::iterator iterator;

    static iterator getBegin(Container& myContainer)
    {
      return myContainer.begin();
    }

    static iterator getEnd(Container& myContainer)
    {
      return myContainer.end();
    }

    static type& getElement(Container&, iterator i)
    {
      return (*i);
    }
  };
}
#endif
