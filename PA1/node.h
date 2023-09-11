#pragma once

#define NODE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

template <class T1, class T2>
struct node
{
    T1 data;
    T2 data2;
    node* next;
};
