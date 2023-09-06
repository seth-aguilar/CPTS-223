// code source: https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

#include <iostream>
#include "linked_list.h"
#include "node.h"
#include "menu.h"

int main()
{
    menu mainMenu;
    mainMenu.printMenu();
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    return 0;
}