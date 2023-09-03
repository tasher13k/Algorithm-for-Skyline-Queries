#include "graphic creation.h"

namespace graphic {
    void draw_graphic(const vector_type &all_points, const vector_type &skyline_points) {
        sf::RenderWindow window(sf::VideoMode(graphic_constants::window_width, graphic_constants::window_height),
                                "Dataset visualizer");

        // run the program as long as the window is open
        while (window.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event = {};
            while (window.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            coordinate_axis_model coordinate_axis{};
            std::vector<point_model> all_dataset;
            std::vector<point_model> only_skyline_points;

            for (auto &cur_point: all_points) {
                all_dataset.emplace_back(cur_point);
            }
            for (auto &cur_point: skyline_points) {
                only_skyline_points.emplace_back(cur_point, true);
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...

            for (auto &pnt: all_dataset) {
                window.draw(pnt.get_point());
            }
            for (auto &pnt: only_skyline_points) {
                window.draw(pnt.get_point());
            }

            window.draw(coordinate_axis.get_axis());
            window.draw(coordinate_axis.get_left_top_triangle());
            window.draw(coordinate_axis.get_right_bottom_triangle());

            // end the current frame
            window.display();
        }
    }

    point_model::point_model(const point_type &point_from_dataset, bool is_skyline) {
        auto x_coordinate = point_from_dataset.x() + graphic_constants::zero_of_x_axis;
        auto y_coordinate =
                graphic_constants::window_height - graphic_constants::zero_of_y_axis - point_from_dataset.y();
        circle_.setPosition(static_cast<float>(x_coordinate), static_cast<float>(y_coordinate));
        circle_.setRadius(4.f);
        if (is_skyline) {
            circle_.setFillColor(sf::Color::Red);
        } else {
            circle_.setFillColor(sf::Color::White);
        }
    }

    coordinate_axis_model::coordinate_axis_model() {
        //lines for coordinate axis
        lines.setPrimitiveType(sf::Lines);
        lines.append(sf::Vector2f(graphic_constants::zero_of_x_axis, graphic_constants::zero_of_y_axis)); //left-top
        lines.append(sf::Vector2f(graphic_constants::zero_of_x_axis, graphic_constants::window_height -
                                                                     graphic_constants::zero_of_y_axis)); //left-bottom
        lines.append(sf::Vector2f(graphic_constants::zero_of_x_axis,
                                  graphic_constants::window_height - graphic_constants::zero_of_y_axis));
        lines.append(sf::Vector2f(graphic_constants::window_width - graphic_constants::zero_of_x_axis,
                                  graphic_constants::window_height -
                                  graphic_constants::zero_of_y_axis)); //right-bottom

        //left-top triangle
        left_top_triangle.setRadius(10.f);
        left_top_triangle.setPointCount(3);
        left_top_triangle.setPosition(int(graphic_constants::zero_of_x_axis / 3), 0);

        //right-bottom triangle
        right_bottom_triangle.setRadius(10.f);
        right_bottom_triangle.setPointCount(3);
        right_bottom_triangle.setPosition(graphic_constants::window_width - 5, graphic_constants::window_height -
                                                                               1.6 *
                                                                               graphic_constants::zero_of_y_axis);
        right_bottom_triangle.rotate(90.f);
    }
}
