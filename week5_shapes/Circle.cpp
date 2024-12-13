#include "Circle.h"
#include <iostream>


//////////////////////////////////////////////////////////////////////////////
// Canvas and Cimg cannot be used on Linux, 								//
// please make sure to leave it commented if you want test to run on GitLab //
// You can remove comments when you run your exercise locally on Windows .  //
//////////////////////////////////////////////////////////////////////////////

// Constructor
Circle::Circle(Point center, double radius, std::string type, std::string name)
	: Shape(name, type),
	_center(center)
{
	this->_radius = radius;
	if (_radius < 0)
	{
		std::cerr << "Error! Radius cannot be negative.";
		exit(1);
	}
}

// Destructor
Circle::~Circle()
{}

Point Circle::getCenter() const
{
	return this->_center;
}

double Circle::getRadius() const
{
	return this->_radius;
}

double Circle::getPerimeter() const
{
	return (2 * PI * _radius);
}

double Circle::getArea() const
{
	return (PI * (_radius * _radius));
}

void Circle::move(Point other)
{
	_center += other;
}

void Circle::printDetails() const
{
	std::cout << "--Circle Details--" << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Center: (" << _center.getX() << ", " << _center.getY() << ")" << std::endl;
	std::cout << "Radius: " << _radius << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
}

void Circle::draw(const Canvas& canvas)
{
  canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}


