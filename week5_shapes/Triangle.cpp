#include "Triangle.h"
#include <iostream>


//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

// Constructor
Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name)
    : Polygon(name, type)
{
    _points.push_back(a);
    _points.push_back(b);
    _points.push_back(c);
}

// Destructor
Triangle::~Triangle()
{

}

// Using Shloelace formula.
double Triangle::getArea() const
{
    // for this method, I had to figure how to
    // calculate triangle's shape without knowing the 
    // height of it, and the base rib.
    double x1 = _points[0].getX(), y1 = _points[0].getY();
    double x2 = _points[1].getX(), y2 = _points[1].getY();
    double x3 = _points[2].getX(), y3 = _points[2].getY();

    // The Shoelace formula
    return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

void Triangle::printDetails() const
{
    std::cout << "--Triangle Details--" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Points:" << std::endl;
    for (size_t i = 0; i < _points.size(); ++i)
    {
        std::cout << "Point " << i + 1 << ": ("
            << _points[i].getX() << ", "
            << _points[i].getY() << ")" << std::endl;
    }
}

void Triangle::draw(const Canvas& canvas)
{
 	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
 	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
