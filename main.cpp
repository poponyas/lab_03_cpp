#include <iostream>
#include "include/Trapeze.h"
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/FiguresArray.h"

int main()
{
    FiguresArray arr;

    int cmd;
    while (true)
    {
        std::cout << "Menu:\n";
        std::cout << "1 - Add Trapeze (center_x center_y base1 base2 height)\n";
        std::cout << "2 - Add Rhombus (center_x center_y diagonal1 diagonal2)\n";
        std::cout << "3 - Add Pentagon (center_x center_y side)\n";
        std::cout << "4 - Show all figures info\n";
        std::cout << "5 - Remove figure by index\n";
        std::cout << "0 - Exit program\n";
        std::cout << "Current figures count: " << arr.getSize() << "\n";
        std::cout << "Enter your choice: ";

        std::cin >> cmd;

        if (cmd == 0)
        {
            break;
        }

        switch (cmd)
        {
        case 1:
        {
            Trapeze *t = new Trapeze();
            std::cout << "Enter trapeze parameters (center_x center_y base1 base2 height): ";
            std::cin >> *t;
            arr.addFigure(t);
            std::cout << "Trapeze added successfully!\n\n";
            break;
        }
        case 2:
        {
            Rhombus *r = new Rhombus();
            std::cout << "Enter rhombus parameters (center_x center_y diagonal1 diagonal2): ";
            std::cin >> *r;
            arr.addFigure(r);
            std::cout << "Rhombus added successfully!\n\n";
            break;
        }
        case 3:
        {
            Pentagon *p = new Pentagon();
            std::cout << "Enter pentagon parameters (center_x center_y side): ";
            std::cin >> *p;
            arr.addFigure(p);
            std::cout << "Pentagon added successfully!\n\n";
            break;
        }
        case 4:
        {
            if (arr.getSize() == 0)
            {
                std::cout << "No figures in the array yet.\n\n";
            }
            else
            {
                std::cout << "\n=== All Figures Information ===\n";
                arr.printAllInfo();
                std::cout << "Total area of all figures: " << arr.totalArea() << "\n\n";
            }
            break;
        }
        case 5:
        {
            if (arr.getSize() == 0)
            {
                std::cout << "No figures to remove.\n\n";
            }
            else
            {
                std::cout << "Enter index of figure to remove (0-" << arr.getSize() - 1 << "): ";
                size_t idx;
                std::cin >> idx;

                try
                {
                    arr.removeFigure(idx);
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

    return 0;
}