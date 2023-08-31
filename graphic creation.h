#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
#include <SFML/Graphics.hpp>
#include "data set.h"

void draw_graphic(const vector_type & all_points, const vector_type & skyline_points);

namespace graphic_constants{
    inline constexpr int window_height {800};
    inline constexpr int window_width {1000};
    inline constexpr int zero_of_x_axis {15};
    inline constexpr int zero_of_y_axis {15};
}

struct point_model{
    point_model() = default;

    explicit point_model(const point_type & point_from_dataset, bool is_skyline = false){
        auto x_coordinate = point_from_dataset.x() + graphic_constants::zero_of_x_axis;
        auto y_coordinate = graphic_constants::window_height - graphic_constants::zero_of_y_axis - point_from_dataset.y();
        circle_.setPosition(sf::Vector2f(x_coordinate, y_coordinate));
        circle_.setRadius(4.f);
        if(is_skyline){
            circle_.setFillColor(sf::Color::Red);
        } else{
            circle_.setFillColor(sf::Color::White);
        }
    }

    decltype(auto) get_point(){
        return circle_;
    }

private:
     sf::CircleShape circle_;
};

struct coordinate_axis_model{
    coordinate_axis_model(){

        //lines for coordinate axis
        lines.setPrimitiveType(sf::Lines);
        lines.append(sf::Vector2f(graphic_constants::zero_of_x_axis, graphic_constants::zero_of_y_axis)); //left-top
        lines.append(sf::Vector2f(graphic_constants::zero_of_x_axis, graphic_constants::window_height - graphic_constants::zero_of_y_axis)); //left-bottom
        lines.append(sf::Vector2f(graphic_constants::zero_of_x_axis, graphic_constants::window_height - graphic_constants::zero_of_y_axis));
        lines.append(sf::Vector2f(graphic_constants::window_width - graphic_constants::zero_of_x_axis, graphic_constants::window_height - graphic_constants::zero_of_y_axis)); //right-bottom

        //left-top triangle
        left_top_triangle.setRadius(10.f);
        left_top_triangle.setPointCount(3);
        left_top_triangle.setPosition(int(graphic_constants::zero_of_x_axis / 3), 0);

        //right-bottom triangle
        right_bottom_triangle.setRadius(10.f);
        right_bottom_triangle.setPointCount(3);
        right_bottom_triangle.setPosition(graphic_constants::window_width - 5, graphic_constants::window_height - 1.6 * graphic_constants::zero_of_y_axis);
        right_bottom_triangle.rotate(90.f);
            }

    decltype(auto) get_axis(){
        return lines;
    }

    decltype(auto) get_left_top_triangle(){
        return left_top_triangle;
    }

    decltype(auto) get_right_bottom_triangle(){
        return right_bottom_triangle;
    }

private:
    sf::VertexArray lines;
    sf::CircleShape left_top_triangle;
    sf::CircleShape right_bottom_triangle;
};

#endif //ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
