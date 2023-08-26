#include <random>
#include "data set.h"
#include <iostream>

data_set::data_set() {
    std::random_device dev;
    std::mt19937 engine(dev()); // for always new random values
    std::uniform_int_distribution<size_t> u (constants::min_value_of_coordinate, constants::max_value_of_coordinate);// generates unsigned random integers
    for (auto& cur_point : data_) {
        cur_point = {u(engine), u(engine)};
    }
}

void data_set::prnt() {
    for(auto c_point : data_){
        std::cout <<  "(" << c_point.x << ", " << c_point.y << ")" << std::endl;
    }
}

Point data_set::get_point_from_data(int index) {
    return data_[index];
}