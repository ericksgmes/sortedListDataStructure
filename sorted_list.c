#include <stdio.h>
#include <stdlib.h>
#include "sorted_list.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertOrdered(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("Lista vazia\n");
        return;
    }
    Node* temp = *head;
    if ((*head)->data == data) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Elemento não encontrado\n");
        return;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

bool searchNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool isEmpty(Node* head) {
    return head == NULL;
}

void clearList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
