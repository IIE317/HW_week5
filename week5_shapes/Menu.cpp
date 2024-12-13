#include "Menu.h"
#include <iostream>

Menu::Menu() 
{
}

Menu::~Menu()
{
}

// Non-direct vector use.
void Menu::addShape(Shape* _shape)
{
    // Not using vector directly because 
    // Shape is an abstractic class, so no real
    // storing can be implented there.
    // Instead, using a raw pointer, to have acces
    // to the type - Shape.
    _shapes.push_back(_shape);
    std::cout << "Shape added successfully!\n";
}

void Menu::displayShapes() const
{
    if (_shapes.empty()) {
        std::cout << "No shapes to display.\n";
        return;
    }

    for (size_t i = 0; i < _shapes.size(); ++i)
    {
        _shapes[i]->printDetails();
    }
}

void Menu::modifyShape(size_t index)
{
    if (index >= _shapes.size())
    {
        // If index is bigger than number of shapes..
        std::cout << "Invalid index! Cannot modify.\n";
        return;
    }
    // New values to be updated
    double x = 0;
    double y = 0;
    // The shape to modify...
    Shape* shp = _shapes[index];

    std::cout << "Modifying shape: " << _shapes[index]->getName() << "\n";
    std::cout << "Please enter new values (X and Y) of the shape.\nNew X value - ";
    std::cin >> x;
    std::cout << "\nNew Y value - ";
    std::cin >> y;

    // Creating new point
    Point newPoint(x, y);

    // Updating values of current point with new point's values.
    shp->move(newPoint);
}

void Menu::removeShape(size_t index)
{
    if (index >= _shapes.size())
    {
        // If index is bigger than the number of shapes
        std::cout << "Invalid index! Cannot remove.\n";
        return;
    }

    delete _shapes[index]; // Free the memory for the shape
    _shapes.erase(_shapes.begin() + index); // Remove pointer from vector
    std::cout << "Shape removed successfully.\n";
}

void Menu::clearShapes()
{
    for (Shape* shape : _shapes)
    {
        // Free memory for each shape (bcs using raw ptr)
        delete shape;
    }

    _shapes.clear();
    std::cout << "All shapes have been cleared.\n";
}

void Menu::exitMenu()
{
    clearShapes(); // Cleanup before exiting
    std::cout << "Exiting the menu.\n";
    exit(0);
}

// Helper functions for easier programming of main.
bool Menu::isEmpty() const
{
    return _shapes.empty();
}

const std::vector<Shape*>& Menu::getShapes() const
{
    return _shapes;
}