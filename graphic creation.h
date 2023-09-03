#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H

#include <SFML/Graphics.hpp>
#include "data set.h"

namespace graphic {
    void draw_graphic(const vector_type &all_points, const vector_type &skyline_points);

    namespace graphic_constants {
        inline constexpr size_t window_height{800};
        inline constexpr size_t window_width{1000};
        inline constexpr size_t zero_of_x_axis{15};
        inline constexpr size_t zero_of_y_axis{15};
    }

    struct point_model {
        point_model() = default;

        explicit point_model(const point_type &point_from_dataset, bool is_skyline = false);

        decltype(auto) get_point() {
            return circle_;
        }

    private:
        sf::CircleShape circle_;
    };

    struct coordinate_axis_model {
        coordinate_axis_model();

        decltype(auto) get_axis() {
            return lines;
        }

        decltype(auto) get_left_top_triangle() {
            return left_top_triangle;
        }

        decltype(auto) get_right_bottom_triangle() {
            return right_bottom_triangle;
        }

    private:
        sf::VertexArray lines;
        sf::CircleShape left_top_triangle;
        sf::CircleShape right_bottom_triangle;
    };
}

#endif //ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
