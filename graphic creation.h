#ifndef ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
#define ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
#include <SFML/Graphics.hpp>
#include "data set.h"

void draw_graphic(const vector_type & all_points, const vector_type & skyline_points);

//struct skyline_model{
//   explicit skyline_model(const vector_type & set_of_points){
//       lines.setPrimitiveType(sf::LineStrip);
//        for(auto & cur_point : set_of_points) {
//            lines.append(sf::Vector2(cur_point.x(), cur_point.y()));
//        }
//    }
//
//    decltype(auto) get_lines() const {
//        return lines;
//   }
//
//private:
//    sf::VertexArray lines;
//};

struct point_model{
    point_model() {}

    point_model(const point_type & point_from_dataset, bool is_skyline = false){
        circle_.setPosition(point_from_dataset.x(), point_from_dataset.y());
        circle_.setRadius(5.f);
        if(is_skyline){
            circle_.setFillColor(sf::Color::Red);
        } else{
            circle_.setFillColor(sf::Color::Blue);
        }

    }

    decltype(auto) get_point(){
        return circle_;
    }

private:
     sf::CircleShape circle_;
};

struct coordinate_axes_model{

};

#endif //ALGORITHM_FOR_SKYLINE_QUERIES_GRAPHIC_CREATION_H
