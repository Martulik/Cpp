#ifndef POINT_HPP
#define POINT_HPP

#include <vector>
#include <iosfwd>

namespace dushechkina
{
	struct Point
	{
		int x;
		int y;
	};

	std::istream& operator>>(std::istream& in, Point& point);
	std::ostream& operator<<(std::ostream& out, const Point& point);

	using Shape = std::vector< Point >;
}
#endif
