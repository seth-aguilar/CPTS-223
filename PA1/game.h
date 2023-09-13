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
	void runGame(profile player, linked_list<std::string, std::string> cmdList);
	profile loadProfile();
	void printMenu();
	void addCmd(linked_list<std::string, std::string> cmdList);
	void removeCmd(linked_list<std::string, std::string> cmdList);
	profile addProfile();
	void saveProfile(profile player);
	void populateProfiles(profile pList[]);
	void updateProfile(profile player);
};

std::ofstream& operator<< (std::ofstream& lhs, profile rhs);
