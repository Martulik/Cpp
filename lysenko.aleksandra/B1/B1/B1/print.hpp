#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>

namespace lysenko
{
  template< template< typename > typename printBy, typename container_type >
  void print(container_type& container, bool withSeparator)
  {
    typedef printBy< container_type > printStrategy;
    typedef typename printStrategy::iterator iterator;

    for (iterator i = printStrategy::getBegin(container); i != printStrategy::getEnd(container); ++i)
    {
      std::cout << printStrategy::getElement(container, i);
      if (withSeparator)
      {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
}

#endif