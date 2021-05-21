#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
namespace dushechkina
{
	struct Point
	{
		int x;
		int y;
	};

	using Shape = std::vector< Point >;
}
#endif
