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

* ADVANTAGES/DISADVANTAGES LINKED LIST:

Advantage: Linked lists offer straightforward manipulation. Modifying and particularly updating nodes is simpler compared to managing an array across numerous functions.
Disadvantage: Traversing the list can be cumbersome. It necessitates the creation of node pointers and manual navigation, which isn't very efficient.

* ADVANTAGES/DISADVANTAGES ARRAY:

Advantage: Arrays, in comparison, facilitate effortless searching. Locating a specific profile is swift and uncomplicated, especially when the index is known.
Disadvantage: Managing an array across multiple functions can be challenging. For instance, updating a player's score demanded navigating through some convoluted steps that wouldn't be necessary with node pointers.


*/


/*
Currently Working :
    Node and linked list templates
    Menu and choice
    Loading save
    Add and remove commands
    Profile updating
    Game loop
Still needs implementaion :
    Exit procedure
*/