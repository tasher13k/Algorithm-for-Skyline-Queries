#include <chrono>
#include "data set.h"
#include "skyline calculator.h"
#include "graphic creation.h"

using namespace std::chrono;

int main() {
    vector_type dataset = {};
    dataset::fill_vector_of_points_with_random_values(dataset);
    //print_vector_of_points(dataset);

    steady_clock::time_point start = steady_clock::now();
    vector_type result_nn = calculation::get_skyline(dataset);
    steady_clock::time_point end = steady_clock::now();
    steady_clock::duration dur = end - start;

    dataset::print_vector_of_points(result_nn);
    std::cout << "Count of skyline points is " << result_nn.size() << std::endl;
    std::cout << "Calculation time was " << duration<double>(dur).count() << " sec" << std::endl;

    graphic::draw_graphic(dataset, result_nn);

    return 0;
}