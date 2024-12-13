#pragma once
#include "Point.h"
// Uncomment when you want to draw on Canvas and run it locally on windows
#include "Canvas.h" 
#include <string>

class Shape 
{
public:

	// Constructor
	Shape(std::string name, std::string type);

	// Destructor
	virtual ~Shape();

	// Getters
	std::string getType() const;
	std::string getName() const;

	// Methods
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void move(Point other) = 0; // add the Point coordinates to all the points coordinates in the shape
	virtual void printDetails() const = 0;

	//////////////////////////////////////////////////////////////////////////////
	// Canvas and Cimg cannot be used on Linux, 								//
	// please make sure to leave it commented if you want test to run on GitLab //
	// You can remove comments when you run your exercise locally on Windows .  //
	//////////////////////////////////////////////////////////////////////////////

	virtual void draw(const Canvas& canvas) = 0;
	virtual void clearDraw(const Canvas& canvas) = 0;

protected:
	std::string _name;
	std::string _type;
};