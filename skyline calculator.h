#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_SKYLINE_CALCULATOR_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_SKYLINE_CALCULATOR_H
#include "data set.h"

using distance_function_pointer = float (*)(point_type);
namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
using point_type = bg::model::d2::point_xy<float>;
using rtree_type = bgi::rtree<point_type, bgi::rstar<16>>;

float distance_function(point_type);

vector_type get_skyline(vector_type);

#endif //ALGORITHM_FOR_SKYLINE_QUERIES_SKYLINE_CALCULATOR_H
