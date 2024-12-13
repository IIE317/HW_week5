#include "Polygon.h"

Polygon::Polygon(std::string type, std::string name)
	: Shape(type, name)
{
}

Polygon::~Polygon()
{

}

std::vector<Point> Polygon::getPoints() const
{
	return _points;
}

double Polygon::getPerimeter() const
{
	int i = 0;
	double per = 0;

	// loop to go through the whole vector
	for (i = 0; i < _points.size(); i++)
	{
		Point p1 = _points[i];
		Point p2 = _points[(i + 1) % _points.size()];

		double x = p2.getX() - p1.getX();
		double y = p2.getY() - p1.getY();
		per += std::sqrt((x * x) + (y * y));
	}
	return per;
}

void Polygon::move(Point other)
{
	int i = 0;

	// adding to each point.
	for (i = 0; i < _points.size(); i++)
	{
		_points[i] += other;
	}
}