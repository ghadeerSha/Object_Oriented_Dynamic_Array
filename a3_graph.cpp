// a3_graph.cpp


#include "a3.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// You can #include other standard libraries if needed.

using namespace std;

// screen dimensions
const int WIDTH  = 500;
const int HEIGHT = 500;

// graph parameters
const int MIN_NUMS = 10;
const int MAX_NUMS = 100;

int main(int argc, char* argv[])
{
    //
    // check that the user passes in the name of a file
    //
    if (argc != 2) {
        cout << "Error: pass in the name of the data file, e.g.:\n";
        cout << "   ./a3_graph data.txt\n";
        return -1;
    }

    string fname(argv[1]);
    cout << "reading " << fname << "\n";

    //
    // get the data
    //
    std::fstream fs;
     fs.open(fname);

    int_vec arr1;
    // check that there from 1 to MAX_NUMS numbers
    if(arr1.size() < MIN_NUMS || arr1.size() > MAX_NUMS){
        cout << "error: data.txt must have 1 to 100 non-negative integers\n";
        return -1;
    }

    //
    // check that each number is on the range 0 to 499
    for(int i = 0; i < arr1.size(); i++){
        if(arr1.get(i) < 0 || arr1.get(i) > 499){
            cout << "error: data.txt numbers must be in the range 0 to 49\n";
            return -1;
         }
    }

    //
    // create the graphics window
    //
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), 
                         "Assignment 3 Bar Chart");
    win.setFramerateLimit(60);



    //
    // main animation loop
    //
    while (win.isOpen())
    {
        // check all the window's events that were triggered since the last
        // iteration of the loop
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            } 
        } // while win.PollEvent

        // clear the screen
        win.clear(sf::Color::Black);

        //
        // draw the rectangles here
        // for(sf::RectangleShape& r : bars){
        //     win.draw(r);
        // }

        //
        // end the current frame and display the window
        //
        win.display();
    } // while

    return 0;
} // main

