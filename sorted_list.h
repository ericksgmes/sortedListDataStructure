#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertOrdered(Node** head, int data);
void deleteNode(Node** head, int data);
bool searchNode(Node* head, int data);
bool isEmpty(Node* head);
void clearList(Node** head);
void printList(Node* head);

#endif // SORTED_LIST_H
