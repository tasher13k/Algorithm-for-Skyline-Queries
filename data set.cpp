#include <random>
#include "data set.h"

namespace dataset {
    void fill_vector_of_points_with_random_values(vector_type &data) {
        std::random_device dev;
        std::mt19937 engine(dev()); // for always new random values
        std::uniform_real_distribution<float> u(constants::min_value_of_coordinate,
                                                constants::max_value_of_coordinate);// generates real random number in specified range
        for (int i = 0; i < constants::count_of_points_in_dataset; ++i) {
            data.emplace_back(u(engine), u(engine));
        }

    }

    void print_vector_of_points(const vector_type &data) {
        std::cout << "Random generated dataset of " << constants::count_of_points_in_dataset << " points" << std::endl;
        for (auto &c_point: data) {
            std::cout << "(" << c_point.x() << ", " << c_point.y() << ")" << std::endl;
        }
        std::cout << std::endl;
    }
}
