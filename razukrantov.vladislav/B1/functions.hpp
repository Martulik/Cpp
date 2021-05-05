#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

template < typename T >
void print(const T& container)
{
    using iterator = typename T::const_iterator;
    iterator size = container.end();
    for (iterator cur = container.begin(); cur != size; cur++)
    {
        std::cout << *cur << " ";
    }
    std::cout << "\n";
}

#endif
