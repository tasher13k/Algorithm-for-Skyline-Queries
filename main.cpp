#include "data set.h"
#include "skyline calculator.h"
#include "graphic creation.h"

int main() {
    vector_type dataset = {};
    fill_vector_of_points_with_random_values(dataset);
    print_vector_of_points(dataset);

    vector_type result_nn = get_skyline(dataset);
    print_vector_of_points(result_nn);

    //draw_graphic(dataset, result_nn);

    return 0;
}