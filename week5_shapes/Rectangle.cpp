#include "Rectangle.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name)
    : Polygon(name, type)
{
    this->_length = length;
    this->_width = width;
    // Define the 4 points of the rectangle
    _points.push_back(a);        // First point (bottom-left)
    _points.push_back(Point(a.getX() + length, a.getY()));          // Second point (bottom-right)
    _points.push_back(Point(a.getX() + length, a.getY() + width));  // Third point (top-right)
    _points.push_back(Point(a.getX(), a.getY() + width));           // Fourth point (top-left)
}

myShapes::Rectangle::~Rectangle()
{

}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
 	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
 	canvas.clear_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::printDetails() const
{
    std::cout << "--Rectangle Details--" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Length: " << _length << std::endl;
    std::cout << "Width: " << _width << std::endl;
    std::cout << "Points:" << std::endl;
    for (size_t i = 0; i < _points.size(); ++i)
    {
        std::cout << "Point " << i + 1 << ": ("
            << _points[i].getX() << ", "
            << _points[i].getY() << ")" << std::endl;
    }
}

double myShapes::Rectangle::getArea() const
{
    return (this->_length * this->_width);
}