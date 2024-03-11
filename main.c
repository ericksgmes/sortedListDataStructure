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

int main(int argc, char *argv[]) {

    return 0;
}