// code source: https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

/*******************************************************************************************

* Programmer: Seth Aguilar                                                                 *

* Class: CptS 223                                                                          *

* Programming Assignment: PA1                                                              *

* Date:   9/15/2023                                                                        *

* Description:  A game that matches linux commands to their definition                     *

*******************************************************************************************/

#include "game.h"

int main()
{
    srand(time(NULL));
    game game;
    game.Game();
}

/*
Currently Working :
    Node and linked list templates
    Menu and choice
    Loading save
    Add and remove commands
Still needs implementaion :
    Exit procedure
    Profile updating
    Game loop
*/