#include <SFML/Graphics.hpp>
#include <stdio.h> 
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>
#include <windows.h> //sleep


class Square {
protected:
    int x, y;
public:
    sf::RectangleShape shape{ (sf::Vector2f(10, 10)) };
    
    Square() {
        x = 0;
        y = 0;
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(x, y);
    }
    Square(int x, int y) {
        this->x = x;
        this->y = y;
        //square=(sf::Vector2f(10, 10));
        shape.setFillColor(sf::Color::White);
        shape.setPosition(x, y);
    }
};

class Line : public Square {
public:
    //sf::RectangleShape shape{ (sf::Vector2f(2, 10)) };// .setFillColor.(sf::Color::Black);
    Line(int x, int y, bool vh){
        this->x = x;
        this->y = y;
        shape.setFillColor(sf::Color::Black);
        shape.setPosition(x, y);
        if (vh) shape.setSize(sf::Vector2f(2, 12));
        else if (!(vh)) shape.setSize(sf::Vector2f(12, 2));
    }
    
};
/*
class LineHorizontal : public Square {
public:
    sf::RectangleShape shape{ (sf::Vector2f(10, 2)) };
};
*/
int main()
{
    srand(time(NULL));
    int size;
    std::cout << "How big should be your maze, give me numbers (max 50): ";
    std::cin >> size;
    
    //int size;
    //scanf("%i", size);
    
    sf::RenderWindow window(sf::VideoMode(size*10+2, size*10+2), "Maze Generator!", sf::Style::Titlebar | sf::Style::Close);
    
    //sf::RectangleShape square(sf::Vector2f(10, 10));
    //square.setFillColor(sf::Color::White);
    //square.setPosition(0,0);
    // 
    // //Test* test[N]; ->test[(size * i) + j]=new Test(j * 10 + 2 * j, i * 10 + 2 * i+10, (bool) h); WTF
    //Test* arr = (Test*)malloc(sizeof(Test) * N); //without default constructor
    //Test* arr = new Test[N];                    //default construcctor
    //Square** squares=new Square*[size*size];
    Square** squares=new Square*[size*size]; 
    Line** lines=new Line*[size*size]; //without default constructor

    /*
    sf::RectangleShape lineB(sf::Vector2f(2, 12));
    lineB.setFillColor(sf::Color::Blue);
    lineB.setPosition(10, 0);

    sf::RectangleShape lineW(sf::Vector2f(12, 2));
    lineW.setFillColor(sf::Color::Green);
    lineW.setPosition(0, 10);
    */
    //window.draw(square);
    //window.draw(lineB);
    //window.draw(lineW); 

    
    
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
      //.............................DRAWING....................MAZE.....................
        while (draw_maze) {
            draw_maze = false;
            window.clear(sf::Color::White);

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {


                    h = rand() % 2;
                    //std::cout << h << std::endl;

                    squares[(size*i) + j ]= new Square(j * 10 + 2 * j, i * 10 + 2 * i);

                    //window.draw(square);
                    switch (h) {
                    case 0:
                        lines[(size * i) + j]= new Line(j * 10 + 2 * j, i * 10 + 2 * i+10, (bool) h);
                        break;
                    case 1:
                        lines[(size * i) + j] =new Line(j * 10 + 2 * j,  i * 10 + 2 * i, (bool) h);
                        break;
                    default:
                        //std::cout << "case def\n";
                        continue;
                    }
                    
                    
                    for (int k = 0;  k < ((size*i)+(j+1)); k++) {
                        
                        window.draw(squares[k]->shape);
                        window.draw(lines[k]->shape);
                    }
                    window.display();
                    Sleep(10);
                    //std::cout << ((20 * i) + j) << std::endl;
                }
                //if (i == 10) break;
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