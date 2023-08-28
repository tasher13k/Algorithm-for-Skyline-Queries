#include <cmath>
#include <boost/geometry/index/rtree.hpp>
#include "data set.h"

using distance_function_pointer = float (*)(point_type);
namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
using point_type = bg::model::d2::point_xy<float>;
using rtree_type = bgi::rtree<point_type, bgi::rstar<16>>;

float distance_function(point_type p){
    return std::sqrt(p.x() * p.x() + p.y() * p.y());
}

float * boundedNNsearch(rtree_type tree, point_type region_border_point, distance_function_pointer dist_function){

}

void take_element(){

}

void divide_region(point_type divide_point, point_type region, vector_type todo){

}

decltype(auto) fill_rtree(const data_set & all_points){
    rtree_type tree;
    for (auto & it : all_points.data_){
        tree.insert(it);
    }
    return tree;
}

void get_skyline(data_set all_points, distance_function_pointer dist_function = &distance_function){
    vector_type to_do_list = {{constants::max_value_of_coordinate,constants::max_value_of_coordinate}}; // only one element - all space
    rtree_type rtree = fill_rtree(all_points);
    while (!to_do_list.empty()){
        if (boundedNNsearch(rtree, to_do_list[0], dist_function)){
            auto nn = boundedNNsearch(rtree, to_do_list[0], dist_function);
        }
    }
}