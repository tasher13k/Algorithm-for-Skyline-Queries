#include "graphic creation.h"

void draw_graphic(const vector_type & all_points, const vector_type & skyline_points){
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Dataset illustration");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event = {};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //skyline_model sk(all_points);
        std::vector<point_model> all_pnts;
        std::vector<point_model> skyline_pnts;
//    window.draw(sk.get_lines());

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        for(auto & pnt : all_points) {
            all_pnts.emplace_back(pnt);
        }
        for(auto & pnt : skyline_points) {
            skyline_pnts.emplace_back(pnt, true);
        }


        //skyline_model skln(skyline_points);
        //window.draw(skln.get_lines());

        for(auto & pnt : all_pnts){
            window.draw(pnt.get_point());
        }
        for(auto & pnt : skyline_pnts){
            window.draw(pnt.get_point());
        }


        // end the current frame
        window.display();
    }
}