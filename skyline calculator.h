#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_SKYLINE_CALCULATOR_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_SKYLINE_CALCULATOR_H
#include "data set.h"

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
using rtree_type = bgi::rtree<point_type, bgi::rstar<16>>;

namespace calculation{
    vector_type get_skyline(const vector_type &);
}

#endif //ALGORITHM_FOR_SKYLINE_QUERIES_SKYLINE_CALCULATOR_H
