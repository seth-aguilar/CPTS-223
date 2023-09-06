#include "menu.h"
#include <iostream>

void menu::printMenu()
{
	std::cout << "Please select an option below:" << std::endl;
	std::cout << "1. Game rules" << std::endl;
	std::cout << "2. Play game" << std::endl;
	std::cout << "3. Load existing save" << std::endl;
	std::cout << "4. Add command" << std::endl;
	std::cout << "5. Remove command" << std::endl;
	std::cout << "6. Exit" << std::endl;
}
