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
    srand((unsigned)time(NULL));
    game game;
    game.Game();
    return 0;
}

/*
Currently Working :
    Node and linked list templates
    Menu and choice
    Loading save
    Add and remove commands
    Profile updating
Still needs implementaion :
    Exit procedure
    Game loop
*/