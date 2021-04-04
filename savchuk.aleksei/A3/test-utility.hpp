#ifndef TEST_UTILITY_HPP
#define TEST_UTILITY_HPP

#include "rectangle.hpp"
#include "circle.hpp"

namespace lab = savchuk;

lab::Rectangle makeRect(const lab::point_t& p, double w, double h);

lab::Circle makeCirc(const lab::point_t& p, double r);

void checkMoveInvariant(lab::Shape& s, const lab::point_t& p);

void checkMoveInvariant(lab::Shape& s, double dx, double dy);

void checkScaleFrameRect(lab::Shape& s, double k);

void checkScaleArea(lab::Shape& s, double k);

void checkScaleInvalidArgument(lab::Shape& s, double k);

void checkCorrectFrameRect(const lab::Shape& s, const lab::rectangle_t& r);

#endif
