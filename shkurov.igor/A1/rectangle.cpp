#include "rectangle.hpp"

Rectangle::Rectangle(const Rectangle& src):
    Shape(src.center_),
    height_(src.height_),
    width_(src.width_)
{
}

Rectangle::Rectangle(const point_t& pos, const double height, const double width):
    Shape(pos),
    height_(height),
    width_(width)
{  
}

double Rectangle::getArea() const
{
    return height_*width_;
}

rectangle_t Rectangle::getFrameRect() const
{
    rectangle_t rect = {height_, width_, center_};

    return rect;
}

void Rectangle::move(const point_t& new_pos)
{
    center_ = new_pos;
}

void Rectangle::move(const double move_x, const double move_y)
{
    center_.x += move_x;
    center_.y += move_y;
}

