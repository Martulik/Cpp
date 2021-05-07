#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>
#include <stdexcept>
#include <string>

template <typename T >
std::function < bool(T, T) > getSortOrder(const char* order)
{
    std::string ascending = "ascending";
    std::string descending = "descending";
    if (order == nullptr)
    {
        throw std::invalid_argument("Incorrect order");
    }
    if (order == ascending)
    {
        return std::greater< T >();
    }
    if (order == descending)
    {
        return std::less< T >();
    }
    else
    {
        throw std::invalid_argument("Incorrect order");
    }
}

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
