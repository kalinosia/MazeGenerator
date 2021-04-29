#include <SFML/Graphics.hpp>
#include <stdio.h> 
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream> //cout
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
    int wall;
public:
    //sf::RectangleShape shape{ (sf::Vector2f(2, 10)) };// .setFillColor.(sf::Color::Black);
    Line(int x, int y, int vh){
        this->x = x;
        this->y = y;
        shape.setFillColor(sf::Color::Black);
        shape.setPosition(x, y);
        //  _           up 0 
        // |_|   left 3 down 2 right 1
  
        if (vh==0 or vh==2) shape.setSize(sf::Vector2f(14, 2));
        else if (vh==1 or vh==3) shape.setSize(sf::Vector2f(2, 12));
        wall = vh;
    }
    int check_wall(){ //class array function returning..with input array n
        return wall;
    };

    
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

    //int WINAPI GetSystemMetrics(SM_CYBORDER);
    //size_t width = (size_t)GetSystemMetrics(SM_CXSCREEN);
    size_t height = (size_t)GetSystemMetrics(SM_CYSCREEN);

    //std::cout << "width = " << width << "\n";
    std::cout << "height = " << height << std::endl;
    
    
    int size;
    std::cout << "How big should be your maze, give me numbers. [Max = your screen height / 12 (round down)]:  ";
    std::cin >> size;
    
    if (height < size * 12) return 1; std::cout << "To big for your screen!\n";
    
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
            bool found_new_wall = false;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {

                    while (!found_new_wall) {
                        h = rand() % 4;
         
                        switch (h) {
                        case 0:
                            if (i > 0){
                                if (lines[((size * i) + j) - size]->wall == 2) break;
                            }
                            else if (i == 0) break;
                            else {
                                found_new_wall = true;
                                break;
                            }
                        case 1:
                            if (j - 1 == size) break;
                            found_new_wall = true;
                            break;
                        case 2:
                            if (j - 1 == size) break;
                            found_new_wall = true;
                            break;
                        case 3:
                            if (j == 0) break;
                            else if (lines[((size * i) + j) - 1]->wall == 1) break;
                            else {
                                found_new_wall = true;
                                break;
                            }
                        default:
                            continue;
                        }
                    }
                    std::cout << h << std::endl;
                    squares[(size * i) + j] = new Square(j * 10 + 2 * j, i * 10 + 2 * i);

                    if (h == 0) lines[(size * i) + j] = new Line(j * 10 + 2 * j-2, i * 10 + 2 * i -2, h); //new
                    else if (h == 1) lines[(size * i) + j] = new Line(j * 10 + 2 * j-2, i * 10 + 2 * i, h);
                    else if (h == 2) lines[(size * i) + j] = new Line(j * 10 + 2 * j-2, i * 10 + 2 * i + 10, h);
                    else if (h == 3) lines[(size * i) + j] = new Line(j * 10 + 2 * j -2, i * 10 + 2 * i, h);
                    else std::cout << "ERROR!!!!" << std::endl;


                    for (int k = 0;  k < ((size*i)+(j+1)); k++) {
                        
                        window.draw(squares[k]->shape);
                        window.draw(lines[k]->shape);
                    }
                    window.display();
                    Sleep(10);
                    found_new_wall = false;
                    
                }
            }
            draw_maze = false;
        }
        //window.display();
         
        
        //Sleep(1000000); 
        //window.draw(square);
        //window.draw(lineB);
        //window.display();
    }

    return 0;
}