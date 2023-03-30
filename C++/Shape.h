#include <iostream>

class Shape {
    private:
        std::string color;
        bool filled;
    public:
        Shape();
        Shape(color: std::string, filled:bool);
        std::string getColor();
        void setColor(color: std::string);
        bool isFilled();
        void setFilled(filled:bool);

        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
        virtual std::string toString() = 0;
        
};