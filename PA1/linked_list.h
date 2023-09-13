#pragma once

#define LINKED_LIST_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
#include "node.h"

template <class T1, class T2>
class linked_list
{
private:
    node<T1, T2>* head, * tail;

    void recListDestruct(node<T1, T2>* tmp)
    {
        if (tmp != nullptr)
        {
            recListDestruct(tmp->next);
            delete tmp;
        }
    }


public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    ~linked_list()
    {
        recListDestruct(head);
    }

    void add_node(T1 data, T1 data2)
    {
        node<T1, T2>* tmp = new node<T1, T2>;
        tmp->data = data;
        tmp->data2 = data2;
        tmp->next = NULL;

        if (head == NULL)
            insertAtFront(tmp);
        
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void insertAtFront(node<T1, T2>* tmp)
    {
        if (tmp != nullptr) 
        {
            tmp->next = head;
            head = tmp->next;
        }
    }

    void removeNode(T1 data)
    {
        if (head == nullptr)
            return;

        if (head->data == data)
        {
            node<T1, T2>* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }

        node<T1, T2>* temp = head;
        node<T1, T2>* prev = nullptr;
        while (temp != nullptr && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prev->next = temp->next;

        if (temp == tail)
            tail = prev;

        delete temp;
    }


    node<T1, T2>* getHead()
    {
        return head;
    }

    node<T1, T2>* getTail()
    {
        return tail;
    }

    void populateList(std::fstream& infile, T1 data, T1 data2)
    {
        while (!infile.eof())
        {
            std::getline(infile, data, ',');
            std::getline(infile, data2);
            add_node(data, data2);
        }
    }
};
