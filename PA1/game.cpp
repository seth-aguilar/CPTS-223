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
			player = addProfile();
			if (player.name != "NULL")
			{
				runGame(player, cmdList);
			}
			system("pause");
			system("cls");

			break;
		case 3: //Load Previous Game
			system("cls");
			player = loadProfile();
			if (player.name != "NULL")
			{
				runGame(player, cmdList);
			}
			system("pause");
			system("cls");

			break;
		case 4: //Add Command
			system("cls");
			addCmd(cmdList);
			system("pause");
			system("cls");

			break;
		case 5: //Remove Command
			system("cls");
			removeCmd(cmdList);
			system("pause");
			system("cls");

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

void game::runGame(profile player, linked_list<std::string, std::string> cmdList)
{
	std::string cmdName, cmdDes, name;
	int i = 0, size = 0, change = 0;

	size = cmdList.getSize();

	profile pList[100];
	populateProfiles(pList);

	change = gameplayLoop(cmdList.getHead(), pList, player, size);

	while (i < 100 && pList[i].name != player.name) 
	{ 
		if (pList[i].name == player.name) 
		{
			pList[i].points = change;
		}
		i++;
	}

	updateProfile(player);

	return;

}

int game::gameplayLoop(node<std::string, std::string>* head, profile pList[], profile player, int i)
{
	int rand1, rand2, activeCmd, display, answer;
	node<std::string, std::string>* tmp1 = head;
	node<std::string, std::string>* tmp2 = head;
	node<std::string, std::string>* tmp3 = head;
	int count = 0, loopsize = 0;
	system("cls");
	std::cout << "How many round would you like to play?" << std::endl;
	std::cin >> loopsize;
	while (count < loopsize) 
	{
		system("cls");
		rand1 = rand() % i;
		rand2 = rand() % i;
		do 
		{
			activeCmd = rand() % i;
		} while (activeCmd == rand1 || activeCmd == rand2);

		tmp1 = head;
		tmp2 = head;
		tmp3 = head;

		for (int i = 0; i < activeCmd; i++)
		{
			tmp1 = tmp1->next;
		}
		for (int i = 0; i < rand1; i++)
		{
			tmp2 = tmp2->next;
		}
		for (int i = 0; i < rand2; i++)
		{
			tmp3 = tmp3->next;
		}

		display = rand() % 3 + 1;

		std::cout << tmp1->data << std::endl;

		rand1 = rand() % 2;

		if (display == 1)
		{
			std::cout << "1. " << tmp1->data2 << std::endl;
			if (rand1)
			{
				std::cout << "2. " << tmp2->data2 << std::endl;
				std::cout << "3. " << tmp3->data2 << std::endl;
			}
			else
			{
				std::cout << "2. " << tmp3->data2 << std::endl;
				std::cout << "3. " << tmp2->data2 << std::endl;
			}
		}
		if (display == 2)
		{
			if (rand1)
			{
				std::cout << "1. " << tmp2->data2 << std::endl;
				std::cout << "2. " << tmp1->data2 << std::endl;
				std::cout << "3. " << tmp3->data2 << std::endl;
			}
			if (!rand1)
			{
				std::cout << "1. " << tmp3->data2 << std::endl;
				std::cout << "2. " << tmp1->data2 << std::endl;
				std::cout << "3. " << tmp2->data2 << std::endl;
			}
		}
		if (display == 3)
		{
			if (rand1)
			{
				std::cout << "1. " << tmp2->data2 << std::endl;
				std::cout << "2. " << tmp3->data2 << std::endl;
			}
			else
			{
				std::cout << "1. " << tmp3->data2 << std::endl;
				std::cout << "2. " << tmp2->data2 << std::endl;
			}
			std::cout << "3. " << tmp1->data2 << std::endl;
		}

		std::cout << "Select your answer: ";
		std::cin >> answer;

		if (answer == display) 
		{
			answer = 0;
			player.points++;
			std::cout << "Correct! You earn one point. Your point total is now " << std::to_string(player.points) << std::endl << "Type any number to continue" << std::endl;
			while (answer == 0) 
			{
				std::cin >> answer;
			}
		}
		else {
			answer = 0;
			player.points--;
			std::cout << "Wrong answer! You lose one point. Your point total is now " << std::to_string(player.points) << std::endl << "Type any number to continue" << std::endl;
			while (answer == 0) 
			{
				std::cin >> answer;
			}
		}

		count++;
		answer = 0;
		display = 0;
	}

	return player.points;
}

profile game::loadProfile()
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

void game::addCmd(linked_list<std::string, std::string> cmdList)
{
	std::fstream infile("commands.csv");
	std::string file = "", tmpName, tmpDef;

	while (!infile.eof())
	{ 
		std::getline(infile, tmpName);
		if (!file.empty())
		{
			file = file + "\n" + tmpName;
		}
		else
		{
			file = file + tmpName;
		}
	}

	infile.close();
	std::ofstream outfile("commands.csv"); 
	std::cout << "What is the name of the command to be added?" << std::endl;
	std::cin >> tmpName;
	std::cout << "What is the definition of the command to be added?" << std::endl;

	while (tmpDef.length() == 0) 
	{
		std::getline(std::cin, tmpDef);
	}
	tmpDef = "\"" + tmpDef + "\"";
	file = file + "\n" + tmpName + "," + tmpDef;
	outfile << file;
	outfile.close();

	cmdList.add_node(tmpName, tmpDef);
}

void game::removeCmd(linked_list<std::string, std::string> cmdList)
{
	std::fstream infile("commands.csv");
	std::string file = "", tmpName, tmpDef, name;
	std::cout << "What is the name of the command to be removed" << std::endl;
	std::cin >> name;

	cmdList.removeNode(name);

	while (!infile.eof())
	{ 
		std::getline(infile, tmpName, ',');
		if (tmpName != name)
		{ 

			if (!file.empty())
			{
				file = file + "\n" + tmpName;
			}
			else
			{
				file = file + tmpName;
			}
			std::getline(infile, tmpDef);
			file = file + "," + tmpDef;
		}
		else
		{
			std::getline(infile, tmpDef);
		}
	}

	infile.close();
	std::ofstream outfile("commands.csv");

	outfile << file; 
	outfile.close();
}

profile game::addProfile()
{
	std::string newName;
	profile newPlayer;

	std::cout << "Please enter your name" << std::endl;

	std::cin >> newName;

	newPlayer.name = newName;
	newPlayer.points = 0;

	return newPlayer;
}

void game::saveProfile(profile player)
{
	std::fstream infile("profiles.csv");
	std::string file = "", tempName, tempDes;
	while (!infile.eof())
	{ 
		std::getline(infile, tempName, ',');

		if (tempName == player.name)
		{ 
			if (!file.empty()) 
			{
				file = file + "\n" + player.name;
			}
			else 
			{
				file = file + player.name;
			}
			getline(infile, tempDes);
			file = file + "," + std::to_string(player.points);
		}
		else {
			if (!file.empty()) {
				file = file + "\n" + tempName;
			}
			else {
				file = file + tempName;
			}
			getline(infile, tempDes);
			file = file + "," + tempDes;
		}
	}
	infile.close();
	std::ofstream outfile("profiles.csv");
	outfile << file;
	outfile.close();

}

void game::populateProfiles(profile pList[])
{
	std::string temp;
	int count = 0;
	std::fstream infile("profiles.csv");
	while (infile.eof() == true || count >= 100)
	{
		std::getline(infile, pList[count].name, ',');
		std::getline(infile, temp);
		pList[count].points = std::stoi(temp);
		count++;
	}
	infile.close();
}

void game::updateProfile(profile player)
{
	std::fstream infile("profiles.csv");
	std::string file = "", tempName, tempDes;
	while (!infile.eof()) 
	{
		std::getline(infile, tempName, ',');
		if (tempName == player.name)
		{
			if (!file.empty()) 
			{
				file = file + "\n" + player.name;
			}
			else 
			{
				file = file + player.name;
			}
			getline(infile, tempDes);
			file = file + "," + std::to_string(player.points); //update player's score
		}
		else 
		{
			if (!file.empty()) 
			{
				file = file + "\n" + tempName;
			}
			else {
				file = file + tempName;
			}
			getline(infile, tempDes);
			file = file + "," + tempDes;
		}
	}
	infile.close();
	std::ofstream outfile("profiles.csv");
	outfile << file;
	outfile.close();

}

std::ofstream& operator<<(std::ofstream& lhs, profile rhs)
{
	lhs << rhs.name << ',' << rhs.points;
	return lhs;
}