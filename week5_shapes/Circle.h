#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	~Circle();

	// Getters
	Point getCenter() const;
	double getRadius() const;
	
	// override methods if need (virtual + pure virtual)
	double getPerimeter() const override;
	double getArea() const override;
	void move(Point other) override;
	void printDetails() const override;

	//////////////////////////////////////////////////////////////////////////////
	// Canvas and Cimg cannot be used on Linux, 								//
	// please make sure to leave it commented if you want test to run on GitLab //
	// You can remove comments when you run your exercise locally on Windows .  //
	//////////////////////////////////////////////////////////////////////////////

	virtual void draw(const Canvas& canvas);
	virtual void clearDraw(const Canvas& canvas);

private:
	double _radius;
	Point _center;

};