#include <SFML/Graphics.hpp>
#include <stdio.h> 
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>
#include<windows.h> //sleep
void DrawSquare(int num) {
    switch (num)
    {
    case 1:

    default:
        break;
    }
}

int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(400, 400), "Maze Generator!", sf::Style::Titlebar | sf::Style::Close);
    
    sf::RectangleShape square(sf::Vector2f(10, 10));
    square.setFillColor(sf::Color::White);
    square.setPosition(0,0);

    sf::RectangleShape lineB(sf::Vector2f(2, 10));
    lineB.setFillColor(sf::Color::Blue);
    lineB.setPosition(10, 0);

    sf::RectangleShape lineW(sf::Vector2f(10, 2));
    lineW.setFillColor(sf::Color::Green);
    lineW.setPosition(0, 10);

    //window.draw(square);
    //window.draw(lineB);
    //window.draw(lineW); 

    
    int i = 0;
    int j = 0;
    int h;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // window.clear();
      
       
        
        h= rand() % 2;
        std::cout << h << std::endl;
        square.setPosition(i*10+2*i, j*10+2*j);
        window.draw(square);
        switch (h) {
        case 0:
            lineB.setPosition(10+ i*10 + 2*i, j*10 + 2*j);
            window.draw(lineB);
            std::cout << "case 0\n";
            break;
        case 1:
            lineW.setPosition( i * 10 + 2 * i,10+ j * 10 + 2 * j);
            window.draw(lineW);
            std::cout << "case 1\n";
            break;
        default:
            std::cout << "case def\n";
            continue;
        }
        window.display();
        j++;
        std::cout <<"I, J: "<< i<<j<< std::endl;
        if (j == 20) j = 0; i++; 
        
        Sleep(1000); 
        //window.draw(square);
        //window.draw(lineB);
        //window.display();
    }

    return 0;
}