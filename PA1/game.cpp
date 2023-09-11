#include "game.h"

void game::Game()
{
	int choice = 0;
	profile player;
	linked_list<std::string, std::string> cmdList;
	std::string name, def;
	std::fstream infile("commands.csv");
	cmdList.populateList(infile, name, def);

	while (choice != 6)
	{
		printMenu();
		std::cin >> choice;
		switch (choice)
		{
		case 1:	//Game Rules
			system("cls");
			std::cout << "These are the game rules" << std::endl;
			system("pause");
			system("cls");

			break;
		case 2: //Play Game
			system("cls");
			std::cout << "Playing game" << std::endl;
			system("pause");
			system("cls");

			break;
		case 3: //Load Previous Game
			system("cls");
			std::cout << "loading from save" << std::endl;
			system("pause");
			system("cls");

			//player = loadGame();
			//if (player.name != "NULL") { //checking validity
			//	playGame(player);
			//}
			break;
		case 4: //Add Command
			system("cls");
			std::cout << "Add command" << std::endl;
			system("pause");
			system("cls");

			//addCommand(cList);
			break;
		case 5: //Remove Command
			system("cls");
			std::cout << "Remove command" << std::endl;
			system("pause");
			system("cls");

			//removeCommand(cList);
			break;
		case 6: //Exit
			system("cls");
			std::cout << "Exiting program" << std::endl;
			system("pause");
			system("cls");

			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
		system("cls");
	}


}

void game::printMenu()
{
	std::cout << "Please select an option below:" << std::endl;
	std::cout << "1. Game rules" << std::endl;
	std::cout << "2. Play game" << std::endl;
	std::cout << "3. Load existing save" << std::endl;
	std::cout << "4. Add command" << std::endl;
	std::cout << "5. Remove command" << std::endl;
	std::cout << "6. Exit" << std::endl;
}
