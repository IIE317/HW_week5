#include "Shape.h"
#include <iostream>

Shape::Shape(std::string name, std::string type)
{
	this->_name = name;
	this->_type = type;
}

Shape::~Shape()
{}

std::string Shape::getType() const
{
	return this->_type;
}

std::string Shape::getName() const
{
	return this->_name;
}

double Shape::getArea() const
{
	// value doesnt matter, overriden
	return 0.0; // Replaced with the actual formula for the area
}

double Shape::getPerimeter() const
{
	// value doesnt matter, overridden.
	return 0.0; // Replaced with the actual formula for the perimeter
}

void Shape::move(Point other)
{
	// Could (chose not to) insert here a warning message. To be inherited.
}

void Shape::draw(const Canvas& canvas)
{
	std::cerr << "Warning: draw() called on Shape base class. This should be overridden.\n";
}

void Shape::clearDraw(const Canvas& canvas)
{
	std::cerr << "Warning: clearDraw() called on Shape base class. This should be overridden.\n";
}