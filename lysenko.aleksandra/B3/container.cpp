#include "container.h"

#include <iostream>
#include <stdexcept>

lysenko::Container::Iterator::Iterator():
  content_(1),
  index_(1)
{};

lysenko::Container::Iterator::Iterator(unsigned int index)
{
  try
  {
    content_ = 1;
    index_ = 1;
    if ((index >= MINIMUM_INDEX) && (index <= MAXIMUM_INDEX))
    {
      for (unsigned int i = 1; i <= index; ++i)
      {
        content_ *= i;
      }
    }
    else
    {
      std::out_of_range;
    }
  }
  catch (std::out_of_range& err)
  {
    std::cerr << "Index out of rangwe \n";
  }
}

lysenko::Container::Iterator lysenko::Container::begin()
{
  return Iterator(MINIMUM_INDEX);
}

lysenko::Container::Iterator lysenko::Container::end()
{
  return Iterator(MAXIMUM_INDEX);
}
 