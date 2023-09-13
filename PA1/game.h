#pragma once

#define GAME_H
#define _CRT_SECURE_NO_WARNINGS

#include "linked_list.h"
#include "linked_list.h"
#include "node.h"
#include "profile.h"

class game
{
public:
	void Game();
	void runGame(linked_list<std::string, std::string> cmdList, std::fstream profiles);
	void runGame(profile player);
	profile loadGame();
	void printMenu();
	void addCmd(linked_list<std::string, std::string> cmdList);
	void removeCmd(linked_list<std::string, std::string> cmdList);
};

