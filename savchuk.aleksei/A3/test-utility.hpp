#ifndef TEST_UTILITY_HPP
#define TEST_UTILITY_HPP

#include "shape.hpp"

namespace lab = savchuk;

void checkMoveInvariant(lab::Shape& s, const lab::point_t& p);

void checkMoveInvariant(lab::Shape& s, double dx, double dy);

void checkScaleFrameRect(lab::Shape& s, double k);

void checkScaleArea(lab::Shape& s, double k);

void checkScaleInvalidArgument(lab::Shape& s, double k);

#endif
