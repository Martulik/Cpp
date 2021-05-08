#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <functional>
#include <stdexcept>
#include <cstring>

template <typename T >
std::function < bool(T, T) > getSortOrder(const char* order)
{
    if (order == nullptr)
    {
        throw std::invalid_argument("Incorrect order");
    }
    if (!strcmp(order, "ascending"))
    {
        return std::less< T >();
    }
    if (!strcmp(order, "descending"))
    {
        return std::greater< T >();
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

void fillRandom(double* array, int size);
bool isNumber(const char* str);

#endif
