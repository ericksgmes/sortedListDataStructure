#include <stdio.h>
#include "sorted_list.h"

int main() {
    Node* head = NULL;

    insertOrdered(&head, 5);
    insertOrdered(&head, 3);
    insertOrdered(&head, 8);
    insertOrdered(&head, 1);
    insertOrdered(&head, 7);

    printf("Lista ordenada: ");
    printList(head);

    printf("Buscando pelo valor 3: %s\n", searchNode(head, 3) ? "Encontrado" : "Não encontrado");
    printf("Buscando pelo valor 10: %s\n", searchNode(head, 10) ? "Encontrado" : "Não encontrado");

    deleteNode(&head, 3);
    printf("Lista após deletar o valor 3: ");
    printList(head);

    deleteNode(&head, 10);

    printf("A lista está vazia? %s\n", isEmpty(head) ? "Sim" : "Não");

    clearList(&head);
    printf("Lista após limpar: ");
    printList(head);

    return 0;
}
