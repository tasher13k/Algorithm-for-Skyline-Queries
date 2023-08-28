#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_DATA_SET_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_DATA_SET_H
#include <cstdlib> //for size_t
#include <vector>
#include <boost/geometry.hpp>

namespace bg = boost::geometry;
using point_type = bg::model::d2::point_xy<float>;

namespace constants{
    inline constexpr size_t count_of_points_in_dataset {10};
    inline constexpr size_t max_value_of_coordinate = 100;
    inline constexpr size_t min_value_of_coordinate = 1;
}

//struct Point{
//    size_t x;
//    size_t y;
//};

using vector_type = std::vector<point_type>;

struct data_set{
    data_set();
    void prnt();
    point_type get_point_from_data(int);

    vector_type data_;
};
#endif //ALGORITHM_FOR_SKYLINE_QUERIES_DATA_SET_H
