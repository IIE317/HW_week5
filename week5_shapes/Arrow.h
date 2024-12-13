#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	~Arrow();

	// Getters
	Point getSource() const;
	Point getDestination() const;

	// override functions if need (virtual + pure virtual)
	double getArea() const override;
	double getPerimeter() const override;
	void move(Point other) override; // add the Point coordinates to all the points coordinates in the shape
	void printDetails() const override;
	
	
	//////////////////////////////////////////////////////////////////////////////
	// Canvas and Cimg cannot be used on Linux, 								//
	// please make sure to leave it commented if you want test to run on GitLab //
	// You can remove comments when you run your exercise locally on Windows .  //
	//////////////////////////////////////////////////////////////////////////////

	virtual void draw(const Canvas& canvas);
	virtual void clearDraw(const Canvas& canvas);


private:
	Point _start;
	Point _end;
};