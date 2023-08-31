#include <cmath>
#include <boost/geometry/index/rtree.hpp>
#include <queue>
#include "data set.h"
#include "skyline calculator.h"

using queue = std::queue<point_type>;

float default_distance_function(point_type p){
    return std::sqrt(p.x() * p.x() + p.y() * p.y());
}

bool boundedNNsearch(point_type & nn, rtree_type & tree, point_type region_border_point, distance_function_pointer dist_function){
    vector_type result_nn = {};
    tree.query(bgi::nearest(point_type{0, 0}, 1) && bgi::covered_by(bg::model::box( {0, 0}, region_border_point)), std::back_inserter(result_nn));
    if(result_nn.empty()){
        return false;
    }
    nn = result_nn.front();
    tree.remove(nn);
    return true;
}

void divide_region(const point_type & divide_point, queue & todo){
    todo.emplace(point_type{divide_point.x(), todo.front().y()});
    todo.emplace(point_type{todo.front().x(), divide_point.y()});
}

decltype(auto) fill_rtree(const vector_type & all_points){
    rtree_type tree;
    for (auto & it : all_points){
        tree.insert(it);
    }
    return tree;
}

vector_type get_skyline(vector_type all_points){
    vector_type result_nn;
    queue to_do_list;
    to_do_list.emplace(point_type {constants::max_value_of_coordinate,constants::max_value_of_coordinate}); // only one element - all space
    rtree_type rtree = fill_rtree(all_points);
    point_type potential_nn{0, 0};
    while (!to_do_list.empty()){
        if (boundedNNsearch(potential_nn, rtree, to_do_list.front(), default_distance_function)){
            divide_region(potential_nn,   to_do_list);
            result_nn.push_back(potential_nn);
        }
        to_do_list.pop();
    }
    return result_nn;
}