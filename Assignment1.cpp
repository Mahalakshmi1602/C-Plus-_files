#include <iostream>
#include <cmath>
using namespace std;


class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void calculateArea() = 0; // Pure virtual
    virtual ~Shape() {
        cout << name << " destructor called." << endl;
    }
};


class Rectangle : public Shape {
private:
    double length, breadth;
public:
    Rectangle(double l, double b) : Shape("Rectangle"), length(l), breadth(b) {}
    void calculateArea() override {
        cout << "Area of Rectangle: " << length * breadth << endl;
    }
    ~Rectangle() {}
};



class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape("Circle"), radius(r) {}
    void calculateArea() override {
        cout << "Area of Circle: " << M_PI * radius * radius << endl;
    }
    ~Circle() {}
};



class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : Shape("Triangle"), base(b), height(h) {}
    void calculateArea() override {
        cout << "Area of Triangle: " << 0.5 * base * height << endl;
    }
    ~Triangle() {}
};



int main() {
    Shape* shapes[3];
    shapes[0] = new Rectangle(5.0, 3.0);
    shapes[1] = new Circle(4.0);
    shapes[2] = new Triangle(6.0, 2.5);

    cout << "--- Shape Areas ---" << endl;
    for (int i = 0; i < 3; i++) {
        shapes[i]->calculateArea();
    }

    // Free memory
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
