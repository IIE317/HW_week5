#include "Menu.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Arrow.h"
#include <iostream>

using myShapes::Rectangle;

void clearCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Menu menu;
    int choice;

    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "0 - Add a new shape\n";
        std::cout << "1 - Get details on a shape\n";
        std::cout << "2 - Delete all shapes\n";
        std::cout << "3 - Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cout << "Error - wrong input, please try again.\n";
            clearCin();
            continue;
        }


        switch (choice) {
        case 0: {
            int shapeType;
            std::cout << "\n--- Add Shape Menu ---\n";
            std::cout << "1 - Circle\n";
            std::cout << "2 - Rectangle\n";
            std::cout << "3 - Triangle\n";
            std::cout << "4 - Arrow\n";
            std::cout << "Enter shape type: ";
            std::cin >> shapeType;

            if (std::cin.fail())
            {
                std::cout << "Error - wrong input, please try again.\n";
                clearCin();
                continue;
            }

            std::string name;
            std::cout << "Enter shape name: ";
            std::cin >> name;

            switch (shapeType) {
            case 1: {
                double centerX, centerY, radius;
                std::cout << "Enter center X: ";
                std::cin >> centerX;
                std::cout << "Enter center Y: ";
                std::cin >> centerY;
                std::cout << "Enter radius: ";
                std::cin >> radius;
                if (std::cin.fail())
                {
                    std::cout << "Error - wrong input, please try again.\n";
                    clearCin();
                    continue;
                }
                Point center(centerX, centerY);
                menu.addShape(new Circle(center, radius, "Circle", name));
                break;
            }
            case 2: {
                double x, y, length, width;
                std::cout << "Enter bottom-left corner X: ";
                std::cin >> x;
                std::cout << "Enter bottom-left corner Y: ";
                std::cin >> y;
                std::cout << "Enter length: ";
                std::cin >> length;
                std::cout << "Enter width: ";
                std::cin >> width;
                if (std::cin.fail())
                {
                    std::cout << "Error - wrong input, please try again.\n";
                    clearCin();
                    continue;
                }
                Point bottomLeft(x, y);
                menu.addShape(new myShapes::Rectangle(bottomLeft, length, width, "Rectangle", name));
                break;
            }
            case 3: {
                double x1, y1, x2, y2, x3, y3;
                std::cout << "Enter point 1 X: ";
                std::cin >> x1;
                std::cout << "Enter point 1 Y: ";
                std::cin >> y1;
                std::cout << "Enter point 2 X: ";
                std::cin >> x2;
                std::cout << "Enter point 2 Y: ";
                std::cin >> y2;
                std::cout << "Enter point 3 X: ";
                std::cin >> x3;
                std::cout << "Enter point 3 Y: ";
                std::cin >> y3;
                if (std::cin.fail())
                {
                    std::cout << "Error - wrong input, please try again.\n";
                    clearCin();
                    continue;
                }
                Point p1(x1, y1), p2(x2, y2), p3(x3, y3);
                menu.addShape(new Triangle(p1, p2, p3, "Triangle", name));
                break;
            }
            case 4: {
                double x1, y1, x2, y2;
                std::cout << "Enter start point X: ";
                std::cin >> x1;
                std::cout << "Enter start point Y: ";
                std::cin >> y1;
                std::cout << "Enter end point X: ";
                std::cin >> x2;
                std::cout << "Enter end point Y: ";
                std::cin >> y2;
                if (std::cin.fail())
                {
                    std::cout << "Error - wrong input, please try again.\n";
                    clearCin();
                    continue;
                }
                Point start(x1, y1), end(x2, y2);
                menu.addShape(new Arrow(start, end, "Arrow", name));
                break;
            }
            default:
                std::cout << "Invalid shape type.\n";
                break;
            }
            break;
        }
        case 1: {
            menu.displayShapes();
            if (menu.isEmpty())
            {
                break;
            }

            int pick = 0;
            std::cout << "\nWould you like to modify shape, or nah? (0 - yes, 1 - no): ";
            std::cin >> pick;
            if (pick != 1 || pick != 0)
            {
                std::cout << "Number out of range!\n";
                break;
            }

            else if (pick == 1)
            {
                std::cout << "Alright!\n";
            }

            else
            {

                size_t index;
                std::cout << "\nEnter the index of the shape to modify: ";
                std::cin >> index;
                if (std::cin.fail())
                {
                    std::cout << "Error - wrong input, please try again.\n";
                    clearCin();
                    continue;
                }
                menu.modifyShape(index - 1);
                break;
            }
        }
        case 2:
            menu.clearShapes();
            break;
        case 3:
            menu.exitMenu();
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}