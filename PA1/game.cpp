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
			std::cout << "Each round you are shown 3 definitions and 1 Linux command. Earn points by matching the correct definition to it's command." << std::endl;
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
			player = loadGame();
			if (player.name != "NULL")
			{
				runGame(player);
			}
			system("pause");
			system("cls");

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

void game::runGame(linked_list<std::string, std::string> cmdList, std::fstream profiles)
{
}

void game::runGame(profile player)
{
}

profile game::loadGame()
{
	std::fstream infile("profiles.csv");
	std::string name, tmp;
	profile player;
	std::cout << "Please enter a profile name to load:" << std::endl;
	std::cin >> name;

	while (!infile.eof())
	{
		std::getline(infile, tmp, ',');
		if (tmp == name)
		{
			player.name = tmp;
			std::getline(infile, tmp);
			player.points = std::stoi(tmp);
			return player;
			std::cout << "Profile found loading points" << std::endl;
			system("pause");
		}
		std::cout << "Profile not found" << std::endl;
		system("pause");
		player.name = "NULL";
		infile.close();
		return player;

	}

	return player;
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
