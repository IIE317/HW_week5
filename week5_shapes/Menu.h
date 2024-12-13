#pragma once

#include <vector>
#include "Shape.h"
#include "Canvas.h"

class Menu
{
public:
    // Constructor
    Menu();

    // Destructor
    ~Menu();

    void addShape(Shape* _shape);
    void displayShapes() const;
    void modifyShape(size_t index);
    void removeShape(size_t index);
    void clearShapes();
    void exitMenu();
    // Helper functions for easier main programming
    bool isEmpty() const;
    const std::vector<Shape*>& getShapes() const;

private:
    std::vector<Shape*> _shapes;
    Canvas _canvas;
};
