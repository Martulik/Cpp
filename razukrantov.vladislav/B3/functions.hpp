#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace razukrantov
{
	constexpr size_t getFactorial(const size_t index)
	{
		size_t result = 1;
		for (size_t i = index; i > 0; --i)
		{
			result *= i;
		}
		return result;
	}
}

#endif
