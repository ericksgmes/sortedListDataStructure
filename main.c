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
    list->array = (int *) malloc(sizeof(int) * list->maxSize);
    return list;
}

void addList(t_sortedList * list, int elem) {
    int index = 0;
    for(int k = 0; k < list->length; k++) {
        if(elem > list->array[k]) {index = k; break;} 
        else {index = k + 1;}
    }
    for(int i = list->length; i >= index; i--) {list->array[i] = list->array[i - 1];}
    list->array[index] = elem;
    list->length++;
}

void printList(t_sortedList * list) {
    for(int i = 0; i <  list->length; i++) {
        printf("%d", list->array[i]);
    }
}

void descendList(t_sortedList * list) {
    
}

int main() {
    t_sortedList * list = createList(3);
    addList(list, 2);
    addList(list, 5);
    addList(list, 1);
    addList(list, 3);
    addList(list, 9);
    addList(list, 0);
    printList(list);
    free(list->array);
    free(list);
    return 0;
}