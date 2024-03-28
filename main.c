#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int maxSize;
    int length;
} t_sortedList;

t_sortedList * createArray(int size) {
    t_sortedList *list = (t_sortedList *) malloc(sizeof(t_sortedList));
    list->maxSize = size;
    list->length = 0;
    list->array = (int *) malloc(sizeof(int) * list->maxSize);
    return list;
}

void addElemToArray(t_sortedList * list, int elem) {
    int index = 0;
    for(int k = 0; k < list->length; k++) {
        if(elem < list->array[k]) {
            index = k; break;
        } 
        else {
            index = k + 1;
        }
    }
    for(int i = list->length; i >= index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = elem;
    list->length++;
}

void printArray(t_sortedList * list) {
    for(int i = 0; i <  list->length; i++) {
        printf("%d ", list->array[i]);
    }
}

void sortArray(t_sortedList * A) {
    int a = A->length%2;
    int b = 0;
    int c = 0;
    t_sortedList * L = createArray(a);
    t_sortedList * R = createArray(A->length-a);
    for (int i = 0; i <= a; i++) {
        addElemToArray(L, A->array[i]);
    }
    for (int j = a; j < A->length; j++) {
        addElemToArray(R, A->array[j]);
    }
    for (int k = 0; k < A->length; k++) {
        if (L->array[c] < R->array[b]) {
            A->array[k] = L->array[c];
            c++;
        } else {
            A->array[k] = R->array[b];
            b++;
        }
    }
}

void addArray(int * array, int size, t_sortedList * B) {
    if(size > B->maxSize) return;
    for(int i = 0; i < size; i++) {
        addElemToArray(B, array[i]);
    }
}

int main() {
    t_sortedList * list = createArray(6);
    t_sortedList * sortthelist = createArray(7);
    int * b = malloc(sizeof(int)*7);
    b[0] = 6;
    b[1] = 5;
    b[2] = 9;
    b[3] = 1;
    b[4] = 2;
    b[5] = 4;
    b[6] = 0;
    addElemToArray(list, 2);
    addElemToArray(list, 9);
    addElemToArray(list, 1);
    addElemToArray(list, 5);
    addElemToArray(list, 0);
    addArray(b, 7, sortthelist);
    addArray(list->array,5,sortthelist);
//    printf("\n@@%d\n", sortthelist->length);
//    printArray(sortthelist);
    free(list->array);
    free(list);
    return 0;
}