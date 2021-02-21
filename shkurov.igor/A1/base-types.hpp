#ifndef _BASE_TYPES_HPP_
#define _BASE_TYPES_HPP_

struct point_t 
{
    double x;
    double y;
};


struct rectangle_t 
{
    double height;
    double width;
    point_t pos;
};

#endif