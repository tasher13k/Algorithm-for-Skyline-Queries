#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_DATA_SET_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_DATA_SET_H
#include <cstdlib> //for size_t
#include <vector>
#include <iostream>
#include <boost/geometry.hpp>

namespace bg = boost::geometry;
using point_type = bg::model::d2::point_xy<float>;
using vector_type = std::vector<point_type>;

namespace constants{
    inline constexpr size_t count_of_points_in_dataset {100};
    inline constexpr size_t max_value_of_coordinate = 750;
    inline constexpr size_t min_value_of_coordinate = 10;
}

void print_vector_of_points(const vector_type &);
void fill_vector_of_points_with_random_values(vector_type &);

#endif //ALGORITHM_FOR_SKYLINE_QUERIES_DATA_SET_H
