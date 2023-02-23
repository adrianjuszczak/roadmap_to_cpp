#include <iostream>
#include <memory>
#include <vector>
#include <utility>

namespace anjk
{
    class Shape
    {
    public:
        virtual ~Shape() {
            std::cout << "Shape DTOR.\n";
        }
        virtual void printShape() = 0;
    };

    class Rectangle : public Shape
    {
    public:
        ~Rectangle() {
            std::cout << "Rectangle DTOR.\n";
        }
        void printShape() override {
            std::cout << "Rectangle \n";
        }
    };

    class Triangle : public Shape
    {
    public:
        ~Triangle() {
            std::cout << "Triangle DTOR.\n";
        }
        void printShape() override {
            std::cout << "Triangle \n";
        }
    };

    class ShapePrinter
    {
    public:
        ShapePrinter(Shape &shape) {
            std::cout << "ShaperPrinter CTOR. \n"
                      << "Shape Type: ";
            shape.printShape();
        }
    };
}

int main()
{
    {
        std::vector<std::unique_ptr<anjk::Shape>> shapes;
        shapes.push_back(std::make_unique<anjk::Rectangle>());

        for(auto &shape : shapes) {
            shape->printShape();
        }
    }
}