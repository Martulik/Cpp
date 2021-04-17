#include <iostream>
#include <vector>

template <typename T>
void print(T& cont, std::ostream& out)
{
  for (typename T::iterator i = cont.begin(); i != cont.end(); i++)
  {
    out << *i << ' ';
  }
  out << '\n';
}
