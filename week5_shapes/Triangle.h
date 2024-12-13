#include "Polygon.h"
#include <string>

class Triangle : public Polygon
{
public:

	// Constructor
	Triangle(Point a, Point b, Point c, std::string type, std::string name);

	// Destructor
	~Triangle();
	
	// override functions if need (virtual + pure virtual)
	double getArea() const override;
	void printDetails() const override;

	//////////////////////////////////////////////////////////////////////////////
	// Canvas and Cimg cannot be used on Linux, 								//
	// please make sure to leave it commented if you want test to run on GitLab //
	// You can remove comments when you run your exercise locally on Windows .  //
	//////////////////////////////////////////////////////////////////////////////

	virtual void draw(const Canvas& canvas);
	virtual void clearDraw(const Canvas& canvas);
};