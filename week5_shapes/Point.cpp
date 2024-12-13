#include "Point.h"
#include <iostream>


Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(double x, double y)
{
	this->_x = x;
	this->_y = y;
}

Point::~Point()
{}

double Point::getX() const
{
	return this->_x;
}

double Point::getY() const
{
	return this->_y;
}

Point Point::operator+(const Point& other) const
{
	return Point(this->_x + other._x, this->_y + other._y);
}

Point& Point::operator+=(const Point& other)
{
	_x += other._x;
	_y += other._y;
	return *this; // returning new positions of x and y
}

double Point::distance(const Point& other) const
{
	return std::sqrt(std::pow(_x - other._x, 2) + std::pow(_y - other._y, 2));
}