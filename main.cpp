#include <SFML/Graphics.hpp>
#include <stdio.h> 
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>
#include <windows.h> //sleep


class Square {
public:
    int x, y;
    sf::RectangleShape square{ (sf::Vector2f(10, 10)) };
    //Square();
    Square(int x, int y) {
        this->x = x;
        this->y = y;
        //square=(sf::Vector2f(10, 10));
        square.setFillColor(sf::Color::Yellow);
        square.setPosition(x, y);
    }

    //sf::RectangleShape square() {
        //sf::RectangleShape square(sf::Vector2f(10, 10));
        //square.setFillColor(sf::Color::White);
        //square.setPosition(x, y);
      //  return square;
    //}
    //void draw(sf::RenderWindow wind) {
      //  wind.draw(Square);
    //}
};

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(400, 400), "Maze Generator!", sf::Style::Titlebar | sf::Style::Close);
    
    //sf::RectangleShape square(sf::Vector2f(10, 10));
    //square.setFillColor(sf::Color::White);
    //square.setPosition(0,0);
    Square* squares[20*20];// = new Square; LATER??
    //std::cout << squares[0]<< std::endl;

    //for (int i = 0; i < 20 * 20; i++) squares[i] = NULL;
    
    sf::RectangleShape lineB(sf::Vector2f(2, 12));
    lineB.setFillColor(sf::Color::Blue);
    lineB.setPosition(10, 0);

    sf::RectangleShape lineW(sf::Vector2f(12, 2));
    lineW.setFillColor(sf::Color::Green);
    lineW.setPosition(0, 10);

    //window.draw(square);
    //window.draw(lineB);
    //window.draw(lineW); 

    
    int i = 0;
    int j = 0;
    int h;
    bool draw_maze = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // window.clear();
      
        while (draw_maze) {
            draw_maze = false;
            window.clear(sf::Color::White);
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {


                    h = rand() % 2;
                    //std::cout << h << std::endl;

                    squares[(20*i) + j ] = new Square(i * 10 + 2 * i, j * 10 + 2 * j);

                    //window.draw(square);
                    switch (h) {
                    case 0:
                        lineB.setPosition(10 + i * 10 + 2 * i, j * 10 + 2 * j);
                        window.draw(lineB);
                        //std::cout << "case 0\n";
                        break;
                    case 1:
                        lineW.setPosition(i * 10 + 2 * i, 10 + j * 10 + 2 * j);
                        window.draw(lineW);
                        //std::cout << "case 1\n";
                        break;
                    default:
                        //std::cout << "case def\n";
                        continue;
                    }
                    
                    
                    for (int k = 0;  k < ((20*i)+(j+1)); k++) {
                        
                        window.draw(squares[k]->square);


                    }
                    window.display();
                    Sleep(100);
                    //std::cout << ((20 * i) + j) << std::endl;
                }
                if (i == 10) break;
            }
        }
        //window.display();
         
        
        //Sleep(1000000); 
        //window.draw(square);
        //window.draw(lineB);
        //window.display();
    }

    return 0;
}