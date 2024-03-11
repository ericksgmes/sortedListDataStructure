#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int maxSize;
    int length;
} t_sortedList;

t_sortedList * createList(int size) {
    t_sortedList *list = (t_sortedList *) malloc(sizeof(t_sortedList));
    // ponteiro stack -> struct na heap
    list->maxSize = size;
    list->length = 0;
    list->array = (int *) calloc(sizeof(int), list->maxSize);
    return list;
}

void addList(t_sortedList * list, int elem) {
    elem = 2;
    list->array[0] = elem;
    list->length++;
}

void printList(t_sortedList * list) {
    for(int i = 0; i <  list->length; i++) {
        printf("%d", list->array[i]);
    }
}

int main() {
    t_sortedList * list = createList(3);
    addList(list, 2);
    printList(list);
    return 0;
}