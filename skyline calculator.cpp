#include <boost/geometry/index/rtree.hpp>
#include <queue>
#include "data set.h"
#include "skyline calculator.h"
#include <chrono>

using queue = std::queue<point_type>;
using namespace std::chrono;

bool boundedNNsearch(point_type & nn, rtree_type & tree, point_type region_border_point){
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
    todo.emplace(divide_point.x() - 1, todo.front().y()); // top-left region
    todo.emplace(todo.front().x(), divide_point.y() - 1); // bottom-right region
}

vector_type get_skyline(const vector_type & all_points){
    vector_type result_nn;
    queue to_do_list;
    to_do_list.emplace(constants::max_value_of_coordinate, constants::max_value_of_coordinate); // only one element - all space

    steady_clock::time_point start = steady_clock::now();
    rtree_type rtree(all_points);
    steady_clock::time_point end = steady_clock::now();
    steady_clock::duration dur = end - start;
    std::cout << "Rtree creation time was " << duration<double>(dur).count() << " sec" << std::endl;

    point_type potential_nn{0, 0};
    while (!to_do_list.empty()){
        if (boundedNNsearch(potential_nn, rtree, to_do_list.front())){
            divide_region(potential_nn,   to_do_list);
            result_nn.push_back(potential_nn);
        }
        to_do_list.pop();
    }
    return result_nn;
}