#include "Arrow.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

// Constructor
Arrow::Arrow(Point a, Point b, std::string type, std::string name)
    : Shape(name, type), // Pass arguments to Shape's constructor
    _start(a),           // Initialize point a.
    _end(b)              // Initialize point b.
{
    if (_start.getX() == _end.getX() && _start.getY() == _end.getY())
    {
        std::cerr << "Error! Cant defined both start&end the same position.";
        exit(1);
    }
}

// Destructor
Arrow::~Arrow()
{}

double Arrow::getArea() const
{
    // Arrows do not have an area, hence returning 0.
    return 0;
}

double Arrow::getPerimeter() const
{
    // returns the distance between x-y (perimeter)
    return _start.distance(_end);
}

void Arrow::move(Point other)
{
    _start += other;
    _end += other;
    if (_start.getX() == _end.getX() && _start.getY() == _end.getY())
    {
        std::cerr << "Error! Cant defined both start&end the same position.";
        exit(1);
    }
}

void  Arrow::printDetails() const
{
    std::cout << "--Arrow Details--" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Start Point: (" << _start.getX() << ", " << _start.getY() << ")" << std::endl;
    std::cout << "End Point: (" << _end.getX() << ", " << _end.getY() << ")" << std::endl;
    std::cout << "Perimeter (Length): " << getPerimeter() << std::endl;
}

 void Arrow::draw(const Canvas& canvas)
 {
 	canvas.draw_arrow(_start, _end); // using the variables I have for the line printing
 }

 void Arrow::clearDraw(const Canvas& canvas)
 {
 	canvas.clear_arrow(_start, _end); // using the variables I have for the line erasing
 }

 Point Arrow::getSource() const
 {
     return this->_start;
 }

 Point Arrow::getDestination() const
 {
     return  this->_end;
 }

