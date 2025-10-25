#include <iostream>
#include "include/Trapeze.h"
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/FiguresArray.h"

int main()
{
    FiguresArray array;

    std::cout << "=== Figure Collection Program ===\n";
    std::cout << "You can add as many figures as you want!\n\n";

    int choice;
    while (true)
    {
        std::cout << "Menu:\n";
        std::cout << "1 - Add Trapeze (center_x center_y base1 base2 height)\n";
        std::cout << "2 - Add Rhombus (center_x center_y diagonal1 diagonal2)\n";
        std::cout << "3 - Add Pentagon (center_x center_y side)\n";
        std::cout << "4 - Show all figures info\n";
        std::cout << "5 - Remove figure by index\n";
        std::cout << "0 - Exit program\n";
        std::cout << "Current figures count: " << array.getSize() << "\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (choice == 0)
        {
            std::cout << "Exiting program...\n";
            break;
        }

        switch (choice)
        {
        case 1:
        {
            Trapeze *trapeze = new Trapeze();
            std::cout << "Enter trapeze parameters (center_x center_y base1 base2 height): ";
            std::cin >> *trapeze;
            array.addFigure(trapeze);
            std::cout << "Trapeze added successfully!\n\n";
            break;
        }
        case 2:
        {
            Rhombus *rhombus = new Rhombus();
            std::cout << "Enter rhombus parameters (center_x center_y diagonal1 diagonal2): ";
            std::cin >> *rhombus;
            array.addFigure(rhombus);
            std::cout << "Rhombus added successfully!\n\n";
            break;
        }
        case 3:
        {
            Pentagon *pentagon = new Pentagon();
            std::cout << "Enter pentagon parameters (center_x center_y side): ";
            std::cin >> *pentagon;
            array.addFigure(pentagon);
            std::cout << "Pentagon added successfully!\n\n";
            break;
        }
        case 4:
        {
            if (array.getSize() == 0)
            {
                std::cout << "No figures in the array yet.\n\n";
            }
            else
            {
                std::cout << "\n=== All Figures Information ===\n";
                array.printAllInfo();
                std::cout << "Total area of all figures: " << array.totalArea() << "\n\n";
            }
            break;
        }
        case 5:
        {
            if (array.getSize() == 0)
            {
                std::cout << "No figures to remove.\n\n";
            }
            else
            {
                std::cout << "Enter index of figure to remove (0-" << array.getSize() - 1 << "): ";
                size_t index;
                std::cin >> index;

                try
                {
                    array.removeFigure(index);
                    std::cout << "Figure removed successfully!\n\n";
                }
                catch (const std::out_of_range &e)
                {
                    std::cout << "Error: " << e.what() << "\n\n";
                }
            }
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n\n";
            break;
        }
    }

    if (array.getSize() > 0)
    {
        std::cout << "\n=== Final Results ===\n";
        array.printAllInfo();
        std::cout << "Final total area: " << array.totalArea() << "\n";
    }
    else
    {
        std::cout << "No figures were created.\n";
    }

    return 0;
}