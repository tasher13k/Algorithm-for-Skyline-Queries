#include <random>
#include <iostream>
#include "data set.h"


data_set::data_set() {
    std::random_device dev;
    std::mt19937 engine(dev()); // for always new random values
    std::uniform_int_distribution<size_t> u (constants::min_value_of_coordinate, constants::max_value_of_coordinate);// generates unsigned random integer
    for (int i = 0; i < constants::count_of_points_in_dataset; ++i){
        data_.emplace_back(point_type{u(engine), u(engine)}); //ВАЖНО!!!
    }

}

void data_set::prnt() {
    for(auto& c_point : data_){
        std::cout <<  "(" << c_point.x() << ", " << c_point.y() << ")" << std::endl;
    }
}

point_type data_set::get_point_from_data(int index) {
    return data_[index];
}