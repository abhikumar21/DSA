#include <bits/stdc++.h>
using namespace std;

// Abstract class
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void display() const = 0; // Another pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius; // Area of a circle: πr²
    }
    void display() const override {
        cout << "Circle with radius " << radius << ", Area: " << area() << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width; // Area of a rectangle: length × width
    }
    void display() const override {
        cout << "Rectangle with length " << length << " and width " << width
             << ", Area: " << area() << endl;
    }
};

int main() {
    // Shape obj; // Error: Cannot instantiate an abstract class

    // Instantiate derived classes
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);

    // Use polymorphism to call methods
    circle->display();
    rectangle->display();

    // Cleanup
    delete circle;
    delete rectangle;

    return 0;
}
